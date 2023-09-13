class Solution {
public:
    vector<int> getRow(int rowIndex) {
      int n = 1+rowIndex;
      vector<vector<int>> arr(n);
      for(int i =0; i<n;i++){
        arr[i].resize(i+1);
        arr[i][0] = arr[i][i] = 1 ;
        for(int j = 1 ; j<i;j++){
          arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
        }
      }
      vector<int> ans;
      for(int j=0; j< arr[n-1].size();j++)ans.push_back(arr[n-1][j]);
      return ans;
    }
};