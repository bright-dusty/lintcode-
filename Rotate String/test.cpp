class Solution {
public:
    /*
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // write your code here
        char *tmp = new char[str.length()];
        for (ssize_t i=0; i < str.length(); i++)
            tmp[(i+offset) % str.length()] = str.data()[i];
        str.assign(tmp, str.length());
        delete [] tmp;
        
    }
};