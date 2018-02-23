#include <cstring>
#include <string>
#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <assert.h>

class Solution {
public:

    static size_t prepare(ssize_t map[256], const char *target) {
        size_t length = strlen(target);
        for (size_t i=0; i < length; i++)
            map[target[i]] = i;
        return length;
    }

    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    static int strStr(const char *source, const char *target) {
        // write your code here
        if (!source || !target)
            return -1;
        ssize_t map[256] ;
        memset(map, -1, sizeof(map));

        size_t target_len = prepare(map, target);
        size_t src_len = strlen(source);
        if (!src_len && !target_len) return 0;
        for (ssize_t i=0; i < src_len; ) {
            ssize_t j = 0;
            for (; j < target_len && i+j < src_len; j++)
                if (source[i+j] != target[j]) {
                    if (i+target_len < src_len) {
                        i += target_len - map[source[i+target_len]];
                    }
                    else
                        return -1;
                    break;
                }
                    
            if (j == target_len)
                return i;
            if (i+j >= src_len)
                return -1;
        }
        return -1;
        
    }
};

typedef int (*strstr_func)(const char *, const char *);

int timeit(strstr_func func) {
    const char * src =  "Stack trace:\r\nFrame        Function    Args\r\n000FFFFC470  0018005D20C (000FFFFE3F4, 000FFFFC640, 00000753D90, 000FFFFDE50)\r\n000FFFFC510  0018005E81B (00000000000, 00000000000, 000000000F0, 00000000000)\r\n000FFFFC760  001801211AD (00040100080, 00000750000, 7FFDA1130AD9, 00000750000)\r\n000FFFFCA50  0018011DB41 (00000000000, 00000000000, 00000000000, 00000000000)\r\n000FFFFCBC0  0018011DFE9 (00000000000, 00000000000, 00000000000, 00000000006)\r\n000FFFFCBC0  0018011E1BA (7FFD9E33C4A1, 00000004048, 0018021A088, 00180122EDC)\r\n000FFFFCBC0  0018011E47F (0010040303C, 00100403045, 00000000047, 0018021A00F)\r\n000FFFFCBC0  00180041422 (000FFFFCDF0, 000FFFFCCB0, 00000000000, 00000000000)\r\n000FFFFCC00  001004012CC (00000000020, 30001010000FF00, 00180047B51, 00180046B90)\r\n000FFFFCCB0  00180047BC2 (00000000000, 00000000000, 00000000000, 00000000000)\r\n00000000000  00180045863 (00000000000, 00000000000, 00000000000, 00000000000)\r\n000FFFFFFF0  00180045914 (00000000000, 00000000000, 00000000000, 00000000000)\r\nEnd of stack trace\n", 
               * target = "14 (00000000000,";
    timeval t0, t1;
    gettimeofday(&t0, nullptr);
    int ret = func(src, target);
    gettimeofday(&t1, nullptr);
    double span = (t1.tv_sec - t0.tv_sec) * 1000.0 + 
                  (t1.tv_usec - t0.tv_usec) / 1000.0 ;
    std::cout << "Cost: " << span << "ms" << std::endl;
    return ret;
}

int find(const char *src, const char *target) {
    std::string s(src);
    return s.find(target);
}

int main() {
    int r1 = timeit(Solution::strStr),
        r2 = timeit(find);
    assert(r1 == r2);
}
