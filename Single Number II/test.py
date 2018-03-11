
def singleNumber(nums):
    a = 0
    b = 0
    for i in nums: 
        d = (b ^ i) & ~a
        c = (a & ~i) | (~a & b & i)
        b, a = d, c

    return b


vec = [2,2,2,3,3,3,1];
print singleNumber(vec);


