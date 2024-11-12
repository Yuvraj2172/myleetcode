class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
       sort(items.begin(), items.end());
       int n = items.size();
       int qs = queries.size();

       vector<int> m(n);
       m[0] = items[0][1];

       for(int i =1; i<n;i++){
        m[i] = max(m[i-1], items[i][1]);
       } 

       vector<int> ans(qs); 
       for(int i=0 ; i<qs;i++){
        int q = queries[i];
        vector<int> req = {q, INT_MAX};

        int index = upper_bound(items.begin(), items.end(), req) - items.begin();

        if(index == 0){
            ans[i] = 0;
        }else {
            ans[i] = m[index -1]; 
        }
       }
       return ans;
    }
};