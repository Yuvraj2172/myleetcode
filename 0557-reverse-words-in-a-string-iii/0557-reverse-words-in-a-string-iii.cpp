class Solution {
public:
    string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> v;
    while(ss>> word){
        reverse(word.begin(), word.end());
        v.push_back(word);
    }
    string ans="";
    int n = v.size();
    for(int i=0; i<n;i++){
        if(i!=n-1){
            ans+=v[i];
            ans+=' ';
            continue;
        }
       ans+=v[i];
    }
    return ans;
    }
};