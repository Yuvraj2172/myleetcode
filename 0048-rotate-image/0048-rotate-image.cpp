class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> v(n , vector<int> (m , -1));
         int col = n-1;
        for(int i=0;i<n ; i++){
            int row = 0;
            for(int j =0; j<m;j++){
                v[row][col]=matrix[i][j];
                row++;
            }
            col--;
        }
        for(int i=0;i<n;i++){
            for(int j =0; j < m; j++){
                matrix[i][j] = v[i][j];
            }
            // cout<<"\n";
        }
    }
};