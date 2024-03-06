class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> temp(m,vector<int>(n,0));
        for(int i=0; i<m;i++){
            for(int j =0; j<n;j++){
                temp[i][j] = arr[j][i];
            }
        }
        for(auto& row : temp){
            auto start = row.begin(), end = row.end()-1;
            while(start < end){
                swap(*start, *end);
                start++;
                end--;
            }
        }
        arr = temp;
    }
};