class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> mp;
        for(auto it : trust){
            mp[it[0]] = it[1];    
        }
        int ans =-1, c=0;
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                ans =i;
                c++;
            }
        }
        if(c>1)return -1;
        c=0;
        for(auto it: trust){
            if(it[1]==ans){
            c++;    
            }        
        }
        if(c== n-1)return ans;
        return -1;
    }
};