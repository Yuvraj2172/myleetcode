class Solution {
public:
    string countAndSay(int n) {
        string ans = "1"; int i = 1;
        while(i<n){
            string curr = "";
            for(int j =0; j<ans.size();j++){
                int count = 1;
                while(j+1 < ans.size() && ans[j] == ans[j+1]){
                    count+=1;
                    j++;
                }
                curr += to_string(count) + ans[j];
            }
            i++;
            ans = curr;
        }
        return ans;
    }
};