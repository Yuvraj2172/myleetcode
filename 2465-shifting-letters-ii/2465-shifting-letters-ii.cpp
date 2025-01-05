class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& arr) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        for(int i=0; i < arr.size(); i++){
            int start = arr[i][0], end = arr[i][1];
            int dir = (arr[i][2] == 1) ? 1 : -1;
            diff[start] += dir;
            if(end + 1 < n){
                diff[end + 1] -= dir;
            }
        }
        vector<int> pref(n,0);
        int curr = 0;
        for(int i=0; i<n;i++){
            curr += diff[i];
            pref[i] += curr;
        }

        for(int i=0; i<n;i++){
            int orig = s[i] - 'a';
            int newind = (orig + pref[i]) % 26;
            if(newind < 0){
                newind += 26;
            }
            s[i] = 'a' + newind;
        }
        return s;
    }
};