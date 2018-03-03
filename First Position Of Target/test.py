class Solution:
    # @param nums: The integer array
    # @param target: Target number to find
    # @return the first position of target in nums, position start from 0 
    @staticmethod
    def binarySearch(nums, target):
        # write your code here
        start = 0
        end = len(nums) - 1
        while start <= end:
            mid = (start + end) / 2
            if nums[mid] >= target:
                end = mid - 1
            else:
                start = mid + 1
        if start == len(nums) or nums[start] != target:
            return -1
        return start

print Solution.binarySearch([1, 2, 3, 3, 4, 5, 10], 11)
        