class Solution {
public:
    int minLength(string s) {
        stack<char> st;
      
        int n = s.size();

        for(int i = 0; i<n;i++){
            if(st.size() == 0){
                st.push(s[i]);
                continue;
            }
            if(s[i] == 'B' && st.top() == 'A' ){
                st.pop();
            }
            else if(s[i] == 'D' && st.top() == 'C'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};