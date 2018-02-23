from copy import copy

def permute(arr):
    if len(arr) <= 1:
        yield arr
    else:
        for i, x in enumerate(arr):
            _arr = copy(arr)
            _arr.pop(i)
            for sub in permute(_arr):
                yield [x] + sub

print list(permute(range(4)))    
