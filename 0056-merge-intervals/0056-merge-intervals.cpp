class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> first = intervals[0];
        int start = first[0]; int end = first[1];
        for(int i=0;i<intervals.size();i++){
            vector<int> current = intervals[i];
            if(current[0] <= end){
                end = max(current[1], end);
            }
            else {
                ans.push_back({start , end});
                start = current[0];
                end = current[1];
            }
            
        }
        ans.push_back({start , end});
        return ans;
    }
};