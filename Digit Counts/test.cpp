class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
     
    int count(int k, int n) {
        int cnt = 0;
        do {
            if (n % 10 == k)
                cnt ++;
        } while (n /= 10);
        return cnt;
            
    }
    
    int digitCounts(int k, int n) {
        // write your code here
        int cnt = 0;
        for (int i=0; i <=n; i++)
            cnt += count(k, i);
        return cnt;
    }
};