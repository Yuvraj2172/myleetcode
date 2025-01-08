class Solution {
public:
    bool helper(string s, string target){
        bool f1 = true;
        bool f2 = true;
        int ss = s.size();
        int ts = target.size();
        for(int i = 0; i< s.size(); i++){
            if(s[i]!= target[i]){f1 = false; break;}
        }
        ts--;
        reverse(target.begin(), target.end());
        reverse(s.begin(), s.end());
        for(int i = 0; i< s.size(); i++){
            if(s[i]!= target[i]){f2 = false; break;}
        }
        cout<< f1 <<" : "<<f2;
        cout<<endl;
        return f1 && f2;
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