//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int vis[n][m] ={0};
        for(int i=0; i < n;i++){
            for(int j=0; j <m;j++){
                 if(i==0 || j==0 || i==n-1 || j ==m-1){
                    if(grid[i][j] ==1){
                        vis[i][j] = 1;
                        q.push({i,j});    
                    }
                    
                }
            }
        }
        int drow[] = {-1,0 ,+1,0};
        int dcol[] = {0,+1,0 ,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i < 4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol] == 1){
                    vis[nrow][ncol] =1;
                    q.push({nrow , ncol});
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n;i++){
            for(int j=0; j < m;j++){
                if(vis[i][j]==0 and grid[i][j]==1)cnt++;
            }
        }
        return cnt;
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends