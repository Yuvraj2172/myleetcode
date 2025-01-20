class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
         int n = mat.size();
         int m = mat[0].size();
         vector<int> rc(n,m),cc(m,n);

         unordered_map<int, pair<int,int>> mp;
         for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                mp[mat[i][j]] = {i,j};
            }
         }

         for(int i =0; i< arr.size(); i++){
            int val = arr[i];
            auto [r,c] = mp[arr[i]];

            if(--rc[r] == 0 || --cc[c] == 0)return i;
         }
         return 0;
    }
};