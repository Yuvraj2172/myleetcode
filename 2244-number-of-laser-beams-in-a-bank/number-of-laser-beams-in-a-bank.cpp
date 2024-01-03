class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans =0;
        vector<int> v;
        for(auto it : bank){
            string s = it;
            int c =0;
            for(int i=0; i<s.size(); i++){
                if(s[i] == '1')c++;
            }
            if(c!=0){
                v.push_back(c);
            }
        }
        for(int i=1; i<v.size(); i++){
            int t = (v[i]*v[i-1]);
            ans += t;
        }
        return ans;
    }
};