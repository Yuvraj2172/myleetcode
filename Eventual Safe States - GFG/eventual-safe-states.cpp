//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        vector<int> revadj[v];
        vector<int> indeg(v,0);
        for(int i=0; i<v;i++){
            for(auto it : adj[i]){
                revadj[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<v;i++){
            if(!indeg[i])q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : revadj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends