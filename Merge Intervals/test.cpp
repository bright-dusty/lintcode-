/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    /*
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        vector<Interval> merged;
        if (intervals.empty())
            return merged;
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0].start;
        int end = intervals[0].end;
        
        for (size_t i=1; i < intervals.size(); i++) {
            if (intervals[i].start <= end) {
                if (intervals[i].end <= end)
                    continue;
                else end = intervals[i].end;
            } else {
                merged.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
            
        merged.push_back(Interval(start, end));
        return merged;
    }
};