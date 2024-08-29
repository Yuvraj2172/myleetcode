class Solution {
public:
    void dfs(vector<vector<int>>& arr, int ind, vector<int>& vis){
        vis[ind] = 1;
        for(int i=0; i<arr.size(); i++){
            if(!vis[i]){
                if(arr[i][0] == arr[ind][0])dfs(arr,i,vis);
                if(arr[i][1] == arr[ind][1])dfs(arr,i,vis);
            }
        }

    }
    int removeStones(vector<vector<int>>& arr) {
        int n =  arr.size();
        vector<int> vis(n+1, 0);
        int ans =0;
        for(int i=0; i<arr.size(); i++){
            if(!vis[i]){
                ans++;
                dfs(arr, i, vis);
            }
        }
        return n - ans;
    }
};