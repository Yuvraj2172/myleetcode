class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
       
        vector<int> adj(n,0);
        for(int i=0; i<edges.size();i++){
            // int u = edges[i][0];
            int v = edges[i][1];
           adj[v] = 1;
        
        }
        vector<int> ans;

        for(int i =0; i<n;i++){
            if(adj[i] == 0){
                ans.push_back(i);
            }
        }

        if(ans.size() > 1)return -1;
        return ans[0];
    }
};