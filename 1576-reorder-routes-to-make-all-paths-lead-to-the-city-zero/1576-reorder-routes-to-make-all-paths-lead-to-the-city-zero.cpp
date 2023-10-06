class Solution {
public:
    int ans =0;
    void dfs(int s, unordered_map<int, vector<int>>& mp, unordered_map<int, bool>& vis){
        vis[s] = true;
        for(auto it : mp[s]){
            if(it>=0){
                if(!vis[it]){
                    dfs(it, mp, vis);
                }
            }
            else {  
                it = abs(it);
                if(!vis[it]){
                    ans++;
                    dfs(it, mp, vis);
                }
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& arr) {
        int s = arr.size();
        unordered_map<int, bool> vis;
        unordered_map<int, vector<int>> mp;
       for(int i=0; i<s;i++){
           mp[arr[i][1]].push_back(arr[i][0]);
           mp[arr[i][0]].push_back(-arr[i][1]);
       }
        dfs(0, mp, vis);
       if(ans ==0)return 0;
       return ans;
    }
};