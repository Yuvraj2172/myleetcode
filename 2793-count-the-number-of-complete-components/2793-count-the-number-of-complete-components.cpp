class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& nodes){
        vis[node] = 1; nodes.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, nodes);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n);
        int ans = 0;
        for(int i=0; i<n;i++){
            if(!vis[i]){
                vector<int> nodes;
                dfs(i, adj, vis ,nodes);
                int f = 1;
                
                for(auto i : nodes){
                    unordered_set<int> s(adj[i].begin(), adj[i].end());
                    for(auto j : nodes){
                        if(j == i)continue;
                        if(s.find(j)== s.end()){
                            f=0; break;
                        }
                    }
                }
                ans += f;
            }
        }
        return ans;
    }
};