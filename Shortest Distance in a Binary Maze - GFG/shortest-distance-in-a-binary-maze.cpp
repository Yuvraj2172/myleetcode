//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n , vector<int>(m,1e9));
        dis[source.first][source.second] = 0;
        queue<pair<int, pair<int,int>>> q;
        q.push({0 , {source.first , source.second}});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        if(source.first == destination.first and source.second == destination.second)return 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >=0 and nrow < n and ncol >=0 and ncol <m and grid[nrow][ncol] == 1
                and dist + 1 < dis[nrow][ncol]){
                    dis[nrow][ncol] = 1 + dist;
                    if(nrow == destination.first and ncol == destination.second)return dis[nrow][ncol];
                    q.push({dis[nrow][ncol] , {nrow,ncol}});
                }
                
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends