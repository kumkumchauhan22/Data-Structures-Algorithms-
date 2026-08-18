class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end(), compare);
        
        int last_pos = intervals[0][1];
        int overlapping_intervals = 0;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last_pos) {
                overlapping_intervals++;
            } else {
                last_pos = intervals[i][1];
            }
        }
        
        return overlapping_intervals;
    }
};
