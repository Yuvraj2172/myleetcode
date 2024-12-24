class Solution {
public:

    int diameter(vector<vector<int>>& edges){
        int n = edges.size() + 1 ;
        vector<int> deg(n,0);
        vector<vector<int>> adj(n);

        for(auto it : edges){
            auto u = it[0];
            auto v = it[1];

            adj[u].push_back(v); adj[v].push_back(u);
            deg[u]++; deg[v]++;
        }

        queue<int> q;
        for(int i=0; i<n;i++){
            if(deg[i] == 1)q.push(i);
        }
        int level =0 , left = n;

        for(; left > 2; level++){
            int qz = q.size();
            left -= qz;
            for(int i=0; i<qz; i++){
                int v = q.front(); q.pop();
                for(auto w : adj[v]){
                    if(--deg[w] == 1){
                        q.push(w);
                    }
                }
            }
        }

        return (left == 2 ) ? 2 * level + 1 : 2 * level;


    
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = diameter(edges1);
        int d2 = diameter(edges2);

        return max({d1, d2,(d1 + 1)/2 + (d2 + 1 )/2 + 1});

    }
};