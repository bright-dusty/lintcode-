from copy import copy

class orderedList(list):
    def __init__(self, *args, **kargs):
        super(orderedList, self).__init__(*args, **kargs)
        self._embed_map = {}
        for ele in self:
            self._map_append(ele)
    
    def __contains__(self, ele):
        return ele[0] in self._embed_map
    
    def append(self, ele):
        super(orderedList, self).append(ele)
        self._map_append(ele)
    
    def _map_append(self, ele):
        if ele[0] not in self._embed_map:
            self._embed_map[ele[0]] = [ele[1]]
        else:
            self._embed_map[ele[0]].append(ele[1])
    
    def same(self, ele):
        if ele in self:
            return self._embed_map[ele]
        return []
    
    def __add__(self, rhs):
        return orderedList(super(orderedList, self).__add__(rhs))

def permute(arr):
    if len(arr) <= 1:
        yield orderedList(arr)
    else:
        for i, x in enumerate(arr):
            _arr = copy(arr)
            _arr.pop(i)
            for sub in permute(_arr):
                lst = sub.same(x[0])
                if lst and x[1] > lst[0]:
                    continue
                yield orderedList([x]) + sub 

class Solution:
    @staticmethod
    def permuteUnique(arr):
        _arr = []
        order = {}
        for e in arr:
            if e not in order:
                order[e] = 1
            else:
                order[e] += 1
            _arr.append((e, order[e]))
            
        for sub in permute(_arr):
            yield [e[0] for e in sub]

l = list(Solution.permuteUnique(['A', 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C']))
assert (len(l) == len(set(["".join(i) for i in l])))
print len(l)