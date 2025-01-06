class Solution {
public:
    vector<int> minOperations(string arr) {
        int n = arr.size();
        vector<int> pref(n,0), suff(n,0);
        int ps(0), ss(0);
        int c = 0;
        c = arr[0] == '1' ? 1 : 0;
        for(int i =1 ; i < n ; i++){
            pref[i] = pref[i-1] + c;
            c += arr[i] == '1' ? 1 : 0;
        } 
        c = arr[n-1] == '1' ? 1 : 0;
        for(int i = n-2; i>=0; i--){
            suff[i] = suff[i+1] + c;
             c += arr[i] == '1' ? 1 : 0;
        }

        vector<int> ans(n,0);
        for(int i=0; i<n;i++)ans[i] = pref[i] + suff[i];
        return ans;
    }
};