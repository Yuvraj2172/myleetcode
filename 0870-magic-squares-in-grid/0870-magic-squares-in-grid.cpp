class Solution {
public:

    bool helper(vector<vector<int>>& grid, int i, int j){
        vector<int> count(10,0);
        for(int x =0; x < 3; x++){
            for(int y =0; y < 3 ;y++){
                int n = grid[i+x][j+y];

                if(n <1 || n > 9 || count[n]>0)return 0;
                count[n]++;
            }
        }

        int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];

        for(int x =0; x < 3; x++){
            int eachrowsum = grid[i+x][j] + grid[i+x][j+1] + grid[i+x][j+2];

            if(sum != eachrowsum)return 0;
        }

        for(int y =0; y <3; y++){
            int eachcolsum = grid[i][j + y] + grid[i+1][j+y] + grid[i+2][j+y];
            if(sum != eachcolsum)return 0;
        }

        int diag1sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int diag2sum = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];

        return (sum == diag1sum) && (sum == diag2sum);

    
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans =0;
        int r = grid.size(), c = grid[0].size();

        if(r < 3 || c < 3)return 0;

        for(int i=0; i<=r -3; i++){
            for(int j =0; j<=c -3; j++){
                if(helper(grid, i,j))ans++;
            }
        }
        return ans;
    }
};