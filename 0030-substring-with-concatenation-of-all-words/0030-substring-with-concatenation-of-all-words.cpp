class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size(), len = words[0].size();
        int l=0, flag =0;
        unordered_map<string, int> count , cache;
        vector<int> res;
        for(int i=0;i<m;i++)count[words[i]]++;
        cache = count;
        for(int i=0; i<= n - m*len; i++){
            string curr = s.substr(i+ l*len , len);
            while(count[curr]--){
                l++;
                if(l==m){
                    res.push_back(i);
                    break;
                }
                curr = s.substr(i+l*len , len);
            }
            l=0;
            count = cache;
        }
        return res;
    }
};