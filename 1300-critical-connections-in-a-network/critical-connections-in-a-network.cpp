class Solution {
private:
    int timer = 1;
   void helper(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[],
        int low[], vector<vector<int>>& bridges){
            vis[node] = 1;
            tin[node] = low[node] = timer;
            timer++;
            for(auto it : adj[node]){
                if(it == parent)continue;
                if(vis[it] == 0){
                    helper(it, node, vis, adj, tin, low, bridges);
                    low[node] = min(low[it], low[node]);
                    if(low[it] > tin[node]){
                        bridges.push_back({it, node});
                    }
                    else {
                        low[node] = min(low[node], low[it]);
                    }
                }
                else {
                        low[node] = min(low[node], low[it]);
                    }
            }
        }
public:
    vector<vector<int>> criticalConnections(int n,
    vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> bridges;
        vector<int> vis(n,0);
        int tin[n], low[n];
        helper(0,-1, vis, adj, tin, low, bridges);
        return bridges;
    }
};
