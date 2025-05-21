class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        vector<int> r,c;
        int m = arr.size();
        int n = arr[0].size();
        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){
                if(arr[i][j] == 0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        for(auto ri : r){
            for(int j=0; j < n; j++){
                arr[ri][j] =0;
            }
        }
        for(auto ci : c){
            for(int i=0; i < m; i++){
                arr[i][ci] =0;
            }
        }
    }
};