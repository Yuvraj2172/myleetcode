class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+2];
        for(auto  it : edges){
          adj[it[0]].push_back(it[1]);
          adj[it[1]].push_back(it[0]);
        }
        for(int i =0; i<n+2;i++){
          if(adj[i].size()==n)return i;
        }
        return -1;
    }
};