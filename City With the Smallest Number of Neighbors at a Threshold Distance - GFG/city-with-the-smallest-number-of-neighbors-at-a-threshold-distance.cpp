//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        vector<vector<int>> arr(n , vector<int>(n , 1e9));
        for(auto it : edges){
            int u = it[0];
            int v =it[1];
            int wt = it[2];
            arr[u][v] = wt;
            arr[v][u] = wt;
        }
        for(int i=0; i<n;i++)arr[i][i]=0;
        
        for(int k = 0; k<n;k++){
            for(int i=0; i <n;i++){
                for(int j=0; j<n;j++){
                    if(arr[i][k] == 1e9 or arr[k][j] == 1e9)continue;
                    arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);
                }
            }
        }
        int cntcity = n;
        int cityNo = -1;
        for( int city =0; city<n; city++ ){
            int c =0;
            for(int adjcity =0; adjcity < n; adjcity++){
                if(arr[city][adjcity] <= distanceThreshold ) c++; 
            }
            if(c <= cntcity){
                cntcity = c;
                cityNo = city;
            }
        }
        return cityNo;
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
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends