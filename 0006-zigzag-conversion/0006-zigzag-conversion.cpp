class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows ==1)return s;
        vector<string> v(numRows);
        bool flag = false;
        int i=0;
        for(auto ch : s){
            v[i]+=ch;
            if(i==0 || i==numRows-1)flag = !flag;
            if(flag)i++;
            else i--;
        }
        string ans="";
        for(auto it : v){
            ans+=it;
        }
        return ans;
    }
};