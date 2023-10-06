class Solution {
public:
    int findJudge(int n, vector<vector<int>>& arr) {
        unordered_map<int,int> mp;
        for(auto it : arr){
            mp[it[0]] = it[1];
        }
        int c=0, ans = -1;
        for(int i=1;i<=n;i++){
            if(mp[i] ==0){
                ans = i;
                c++;
            }
        }
        if(c>1)return -1;
        c=0;
        for(auto it : arr){
            if(it[1] == ans)c++;
        }
        if(c==n-1)return ans;
        return -1;
    }
};