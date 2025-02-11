class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(1){
            int res = s.find(part);
            if(res != string::npos){
            s.erase(res,part.size());
            }else {
                break;
            }
        }
        return s;
    }
};