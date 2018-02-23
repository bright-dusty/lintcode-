#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    typedef vector<Point*> line;
    /*
     * @param points: an array of point
     * @return: An integer
     */
    int maxPoints(vector<Point> &points) {
        // write your code here
        vector<line> lines;
        
        if (points.size() < 2) return points.size();
        for (int i=0; i < points.size()-1; i++)
            for (int j=i+1; j < points.size(); j++) 
                lines.push_back(line({&points[i], &points[j]}));
            
                
        for (auto &ln : lines) {
            for (auto &p : points) {
                if (find_if(ln.begin(), ln.end(), [&](Point* &lp){
                    //if (&ln == &lines[2])
                    //cout << lp->x << " " << lp->y << " | " << p.x << " " << p.y << " " << (lp == &p) << endl;
                    return lp == &p;}) == ln.end() && sameLine(ln, p))
                    ln.push_back(&p);

            }
        }
        line::size_type max_point = 2;
        for (auto &ln : lines)
            max_point = max(ln.size(), max_point);
        
            

        return max_point;
        
    }
    
    bool sameLine(line &ln, Point &p) {
        auto iter = ln.begin();
        float k  ; bool k_exists = false, reverse_k_exists = false;
        while ((iter+1) != ln.end()) {
            if ((*iter)->x == p.x && (*iter)->y == p.y)
                return true;
            if (!((*iter)->x == (*(iter+1))->x && (*iter)->y == (*(iter+1))->y)) {
                if (((*iter)->x - (*(iter+1))->x)) {
                    k_exists = true;
                    k = (float((*iter)->y) - (*(iter+1))->y) / ((*iter)->x - (*(iter+1))->x);
                } else {
                    reverse_k_exists = true;
                    k = (float((*iter)->x) - (*(iter+1))->x) / ((*iter)->y - (*(iter+1))->y) ;
                }
            }
            iter ++;
        }
        if ((*(ln.end()-1))->x == p.x && (*(ln.end()-1))->y == p.y)
            return true;
        if (k_exists)
            return k == ((float(p.y) - (*(ln.begin()))->y) / (p.x - (*(ln.begin()))->x));
        if (reverse_k_exists)
            return k == ((float(p.x) - (*(ln.begin()))->x) / (p.y - (*(ln.begin()))->y));
        return true;
    }
};

int main () {
    
    vector<Point> points = 
#include "in.txt"
;
    cout << Solution().maxPoints(points);
}
