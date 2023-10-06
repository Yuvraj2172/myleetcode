class Solution {
public:
    void dfs(int s, vector<vector<int>>& rooms, vector<int>& vis){
        vis[s] = 1;
        for(auto it : rooms[s]){
            if(!vis[it])dfs(it,rooms, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        dfs(0, rooms, vis);
        for(int i=0; i<n;i++){
            if(!vis[i])return 0;
        }
        return 1;
    }
};