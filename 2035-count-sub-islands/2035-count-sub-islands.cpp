class Solution {
public:
    bool dfs(vector<vector<int>>& arr1, vector<vector<int>>& arr2, 
    int m, int n, int i, int j){
        
        if(i<0 || i>=m || j<0 || j>=n || arr2[i][j] == 0)return 1;
        arr2[i][j] = 0;
        
        bool res =1;
        bool d = dfs(arr1, arr2, m,n,i+1,j);
        bool u = dfs(arr1, arr2, m,n,i-1,j);
        bool r = dfs(arr1, arr2, m,n,i,j+1);
        bool l = dfs(arr1, arr2, m,n,i,j-1);

        return l&& u&& d && r && arr1[i][j];

    }
    int countSubIslands(vector<vector<int>>& arr1, vector<vector<int>>& arr2) {
        int m = arr1.size(), n = arr1[0].size();

        int ans  =0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(arr2[i][j] == 1)
                    ans +=dfs(arr1, arr2, m,n,i,j);

            }
        }    
        return ans;
    }
};