class Solution {
public:
    int helper(int a, int b, char op){
        if(op == '+')return a + b;
        else if(op == '-')return a-b;
        else if (op == '*')return a*b;
        return 0;
    }
    vector<int> diffWaysToCompute(string s) {
        vector<int> ans; 
        bool isNumber = 1;
        for(int i=0; i<s.length(); i++){
            if(!isdigit(s[i])){
                isNumber = 0;
                vector<int> left = diffWaysToCompute(s.substr(0,i));
                vector<int> right= diffWaysToCompute(s.substr(i+1));

                for(auto l : left){
                    for(auto r : right){
                        int val = helper(l,r,s[i]);
                        ans.push_back(val);
                    }
                }

            }
        
        }
        if(isNumber == 1)ans.push_back(stoi(s));
        return ans;
    }
};