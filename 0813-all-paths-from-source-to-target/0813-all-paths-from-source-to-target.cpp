class Solution {
public:
    void dfs(int source, int dest, vector<vector<int>>& ans, vector<int> ds, vector<vector<int>>& graph){
        if(source == dest){
            ds.push_back(source);
            ans.push_back(ds);
            // return;
        }
        ds.push_back(source);
        for(auto it : graph[source]){
            dfs(it, dest, ans, ds, graph);
        }
        // ds.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> v;
        int n = graph.size();
        dfs(0,n-1, ans,v, graph);
        return ans;
    }
};