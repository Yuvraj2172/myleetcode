class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) return true;
        
        if(grid2[i][j] == 0) return true;
        grid2[i][j] = 0;

        bool isSubIsland = true;
        if(grid1[i][j] == 0) isSubIsland = false;

        bool right = dfs(i + 1, j, grid1, grid2, n, m);
        bool down = dfs(i, j + 1, grid1, grid2, n, m);
        bool left = dfs(i - 1, j, grid1, grid2, n, m);
        bool up = dfs(i, j - 1, grid1, grid2, n, m);

        return isSubIsland && right && down && left && up;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] == 1) {
                    if(dfs(i, j, grid1, grid2, n, m)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};