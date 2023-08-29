class Solution {
public:
    int bestClosingTime(string s) {
        int cur_penalty = count(s.begin(), s.end(),'Y');
        int cur_hour =0;
        int min_penalty = cur_penalty;
        int earliest_hour = cur_hour;
        int n = s.size();
        for(int i=0; i<n;i++){
            if(s[i] == 'Y'){
                cur_penalty--;     
            }
            else {
                cur_penalty++;
            }
            if(cur_penalty < min_penalty){
                earliest_hour = i+1;
                min_penalty = cur_penalty;
            }
        }
        return earliest_hour;
    }
};