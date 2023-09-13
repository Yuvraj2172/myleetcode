class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        vector<int> ans;
        ans.push_back(1);
        long long int res = 1 ;
        for(int i=1 ;i<n;i++){
          res = res*(n-i);
          res/=i;
          ans.push_back(res);
        }
        return ans;
    }
};