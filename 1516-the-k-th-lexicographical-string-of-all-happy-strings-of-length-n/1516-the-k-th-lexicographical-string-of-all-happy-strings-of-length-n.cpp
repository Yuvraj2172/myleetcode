class Solution {
public:
    void helper(int n, int k, vector<string>& res, vector<char>& v, string& curr){
        if(n == curr.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0; i < v.size(); i++){
            if(!curr.empty() && v[i]== curr.back() )continue;
            curr.push_back(v[i]);
            helper(n,k,res,v,curr);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> res;
        vector<char> v = {'a','b', 'c'};
        string curr = "";
        helper(n,k,res, v, curr);
        return res.size() < k ? "" : res[k-1];
    }
};