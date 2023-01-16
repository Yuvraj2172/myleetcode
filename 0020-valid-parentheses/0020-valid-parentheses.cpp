class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch=='(' or ch=='[' or ch=='{')st.push(ch);
            else {
                if(st.empty() or (st.top()=='(' and ch!=')')  or (st.top()=='[' and ch!=']') or (st.top()=='{' and ch!='}'))return false;
                st.pop();
            }
        }
        return st.empty();
    }
};