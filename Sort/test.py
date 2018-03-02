from ctypes import *
from random import randint
from flask import render_template, Flask, request

import os

c_code = """\
#include <ctime>
#include <sys/time.h>
#include <cstdio>
#include "%s.cpp"

extern "C" {
    
    double sort (int arr[], size_t n) {
        timeval t0, t1;
        gettimeofday(&t0, nullptr);
        if (n)_sort(arr, n);
        gettimeofday(&t1, nullptr);
        double span = (t1.tv_sec - t0.tv_sec) * 1000.0 + 
                      (t1.tv_usec - t0.tv_usec) / 1000.0 ;
        
        //printf("Method : %%s\\n", "%s");
        //printf("Scale : %%d\\n", n);
        //printf("Cost : %%.2f ms\\n", span);
        return span;
    };
}
"""

Implements = [#"BubblingSort", "SelectionSort", "InsertSort", 
              "ShellSort", "MergeSort", "HeapSort", "QuickSort"]

def compile(imp):
    with open("libs.cpp", "w") as f:
        f.write(c_code % (imp, imp))
    return os.system("g++ -O3 -shared -rdynamic libs.cpp -o %s.dll" % imp)

app = Flask("")

@app.route("/")
def gen_and_test():
    start = request.args.get("start", type=int, default=10240)
    end = request.args.get("end", type=int, default=300000)
    step = request.args.get("step", type=int, default=10000)
    results = []
    for imp in Implements:
        dll = "./%s.dll" % imp
        code = "./%s.cpp" % imp
        
        if  not os.path.exists(dll) and compile(imp):
            continue
        if os.stat(dll).st_mtime < os.stat(code).st_mtime:
            compile(imp)
        
        time_spent = []
        scales = list(range(start, end, step))
        for x in scales:
            time_spent.append(test(dll, x))
        avg = sum(time_spent) / len(time_spent)
        results.append({"data":time_spent, "name":imp, "type":"line"})
    return render_template("line-smooth.html", scales=scales, keys=Implements, results=results)

cache = {}
def gen_arr(size):
    arr = (c_int * size)()
    if size in cache:
        for i in range(size):
            arr[i] = cache[size][i]
        return arr
    else:
        for i in range(size):
            arr[i] = randint(-0x80000000, 0x7fffffff)
        cache[size] = arr
        return gen_arr(size)

def test(dllname, size=10000):
    dll = CDLL(dllname)
    arr = gen_arr(size)
    dll.sort.restype = c_double
    spent = dll.sort(arr, size)
    assert all(arr[x] <= arr[x+1] for x in range(size-1))
    return spent

app.run()
