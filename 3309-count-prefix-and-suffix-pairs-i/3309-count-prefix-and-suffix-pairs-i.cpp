class Solution {
public:
    bool helper(string s, string target){
        int ss = s.size();
        int ts = target.size();
        if(ss > ts)return false;
        return (target.substr(0,ss)) == s && (target.substr(ts - ss) == s);
    }
    int countPrefixSuffixPairs(vector<string>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i=0; i < n - 1 ; i++){
            for(int j = i + 1; j < n; j++){
                ans += helper(arr[i], arr[j]);
            }
        }
        return ans;
    }
};