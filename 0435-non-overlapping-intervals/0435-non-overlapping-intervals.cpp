class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        for(int i= 1 ; i< intervals.size();i++){
            vector<int> current = intervals[i];
            if( current[0] >= prevEnd ){
                prevEnd = current[1];
            }
            else {
                ans+=1;
                prevEnd = min(current[1], prevEnd);
            }
        }
        return ans;
    }
};