def comb(arr, n):
    if not n:
        yield []
    for i, e in enumerate(arr):
        _arr = arr[i+1:]
        for sub in comb(_arr, n-1):
            yield sorted([e] + sub)

class Solution:
    
    """
    @param: nums: A set of numbers
    @return: A list of lists
    """
    def subsets(self, nums):
        return reduce(lambda x, y : x+y, [list(comb(nums, n)) for n in range(0, len(nums)+1)], [])

print sum([sum(i+[0]) for i in Solution().subsets(range(20))])
		