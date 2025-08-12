class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1){
            return intervals;
        }
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int previous_start = intervals[0][0];
        int previous_end = intervals[0][1];
        for(int i = 1 ; i< n ;i++){
            int current_start = intervals[i][0];
            int current_end = intervals[i][1];
            // if overlapping
            if(current_start<=previous_end){
                previous_end = max(previous_end, current_end);
            }else{
                // if no overlapping then add the interval
                result.push_back({previous_start,previous_end});
                previous_start = current_start;
                previous_end = current_end;
            }
        }
        result.push_back({previous_start,previous_end});
        return result;
    }
};