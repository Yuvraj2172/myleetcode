class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        vector<pair<int,int>> vp;
        int m = arr.size(), n = arr[0].size();
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(arr[i][j] ==0){
                    vp.push_back({i,j});
                }
            }
        }
        for(int i=0; i<vp.size(); i++){
        int row = vp[i].first, col = vp[i].second;
            for(int r = 0; r < m;r++){
                arr[r][col] =0;
                }
            for(int c=0; c<n;c++){
                arr[row][c]=0;
            }
        }
    }
};