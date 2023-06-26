class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n , vector<int>(m , -1));
        for(int i=0; i < n;i++){
            for(int j=0; j < m;j++){
                if(mat[i][j] == 0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int drow[] = { -1,0,1,0 };
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow < 0 or nrow >= n or ncol<0 or ncol>=m or ans[nrow][ncol]!=-1)continue;
                ans[nrow][ncol] = ans[row][col] +1;
                q.push({nrow, ncol});
            }
        }
        return ans;
    }
};