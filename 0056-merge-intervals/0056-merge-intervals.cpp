class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> first = intervals[0];
        int start = first[0], last = first[1];
        
        for(int i=0; i< n; i++){
            vector<int> current = intervals[i];
            if(current[0] <= last){
                last = max( current[1], last);
            }
            else {
                ans.push_back( {start , last});
                start = current[0];
                last = current[1];
            }
        }
        ans.push_back({start, last});
        return ans;
    }
};