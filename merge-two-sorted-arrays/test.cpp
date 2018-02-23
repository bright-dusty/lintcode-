class Solution {
public:
    /*
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        std::shared_ptr<vector<int>> C (new vector<int>);
        size_t i = 0,
               j = 0;
        for (; i < A.size() && j < B.size(); )
            if (A[i] <= B[j]) 
                C->push_back(A[i++]);
            else
                C->push_back(B[j++]);
        while (i < A.size())
            C->push_back(A[i++]);
        while (j < B.size())
            C->push_back(B[j++]);
        return *C;
        
    }
};