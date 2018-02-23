class Solution:
    """
    @param: n: An integer
    @return: the nth prime number as description.
    """
    def nthUglyNumber(self, n):
        # write your code here
        nums = [1]
        i2 = i3 = i5 = 0
        while len(nums) != n:
            u2 = nums[i2] * 2
            u3 = nums[i3] * 3
            u5 = nums[i5] * 5
            _min = min(u2, u3, u5)
            if _min != nums[-1]:
                nums.append(_min)
            if nums[-1] == u2:
                i2 += 1
            elif nums[-1] == u3:
                i3 += 1
            elif nums[-1] == u5:
                i5 += 1
            #print i2, i3, i5
            #print nums
        return nums[-1]

print Solution().nthUglyNumber(7)