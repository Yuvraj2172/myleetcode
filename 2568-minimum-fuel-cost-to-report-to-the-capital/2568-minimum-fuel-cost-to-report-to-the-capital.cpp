class Solution {
public:
    int dfs(int node, vector<int> adj[], vector<int>& vis, vector<long long>& cost, int seats){
        vis[node] = 1;
        long long persons = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                long long p = dfs(it,adj, vis, cost, seats);
                persons += p;
                long long cars = p / seats;
                if(p%seats!=0){
                    cars++;
                }
                cost[node] += cars + cost[it];
            }
        }
        return persons;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<int> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<long long> cost(n,0);
        dfs(0,adj,vis,cost,seats);
        return cost[0];
    }

};