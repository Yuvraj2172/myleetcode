class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        int i(0), j(0);

        string ans = "";

        while(i < n && j < m){
            if(i == spaces[j]){
                ans += ' ';
                j++;
            }
            else{
                ans += s[i];
                i++;
            }
        }
    
        while(i < n){
            ans += s[i];
            i++;
        }
        return ans;
    }
};