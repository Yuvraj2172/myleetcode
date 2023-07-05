//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        size.resize(n + 1, 0);

        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUp(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUp(parent[node]); // Path Compression.
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUp(u);
        int ulp_v = findUp(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUp(u);
        int ulp_v = findUp(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cntExtras =0;
        for(auto it : edge){
            int u = it[0] , v = it[1];
            if(ds.findUp(u) == ds.findUp(v))cntExtras++;
            else ds.unionBySize(u,v);
        }
        int cntC=0;
        for(int i=0; i<n;i++){
            if(ds.findUp(i) == i)cntC++;
        }
        int ans = cntC-1;
        return (cntExtras>= ans)? ans : -1;
    }
    
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends