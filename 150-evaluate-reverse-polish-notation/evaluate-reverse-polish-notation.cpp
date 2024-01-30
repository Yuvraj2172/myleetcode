class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;
        for(auto it : s){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if(it == "+" ){
                    st.push(a+b);
                }
                if(it == "-" ){
                    st.push(b-a);
                }
                if( it == "*"  ){
                    st.push(a*b);
                }
                if( it == "/"){
                    st.push(b/a);
                }
            }else {
                int a = stoi(it);
                st.push(a);
            }
    }
        return st.top();
    }
};