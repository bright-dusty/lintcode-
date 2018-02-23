class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
     
    size_t pow (size_t base, size_t exp) {
        size_t result = base;
        while (-- exp)
            result *= base;
        return result;
    }
    
    long long trailingZeros(long long n) {
        // write your code here, try to do it without arithmetic operators.
        size_t tail = 0;
        size_t exp = 1;
        size_t inc = 0;
        while (inc=n / pow(5L, exp++))
            tail += inc;
        return tail;
         
    }

};