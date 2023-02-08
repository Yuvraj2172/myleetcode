class Solution {
public:
    int helper(vector<vector<int>>& grid, int m , int n , int i , int j,int** ans){
        if(i==m-1 && j == n-1)return grid[i][j];
        if(i>m-1 || j>n-1){
        return INT_MAX;    
        }
        if(ans[i][j]!=-1)return ans[i][j];
        int x = helper(grid , m , n , i+1,j,ans);
        int y = helper(grid , m , n , i , j+1,ans);
        int sum= grid[i][j] + min(x , y);
        ans[i][j]= sum;
        return sum;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int** ans = new int*[m];
        for(int i=0;i<m;i++){
        ans[i] = new int[n];
        }
        for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
        ans[i][j] = -1;    
        }
        }
        return helper(grid , grid.size(), grid[0].size(),0,0, ans);
    }
};