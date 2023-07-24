class Solution {
public:
    int helper(vector<vector<int>>& grid, int row , int col , int zero , int n , int m){
        if(row<0 || row>= n || col <0 || col >=m || grid[row][col] == -1)return 0;
        if(grid[row][col]==2){
            return zero == -1 ? 1:0;
        }
        zero--;
        grid[row][col]=-1;
        int totalAns = helper(grid , row+1 , col , zero , n , m)
            +helper(grid , row , col+1 , zero , n , m)
            +helper(grid , row-1 , col , zero , n , m)
            +helper(grid , row , col-1 , zero , n , m);
        zero++;
        grid[row][col]=0;
        return totalAns;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0, sx=0, sy=0;
        int n = grid.size() , m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0)zero++;
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        }
        return helper(grid,sx ,sy, zero, n,m);
    }
};