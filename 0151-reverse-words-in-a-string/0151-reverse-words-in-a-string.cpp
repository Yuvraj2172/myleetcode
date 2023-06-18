class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        for(int i=0; i< n; i++){
            string word ="";
            while(i < n and s[i]!=' '){
                word+=s[i++];
            }
            if(!word.empty())st.push(word);
        }
        s.erase();
        int count=st.size();
        while(!st.empty()){
            s+= st.top();
            if(count!=1)s.push_back(' ');
            count--;
            st.pop();
        }
        return s;
    }
};