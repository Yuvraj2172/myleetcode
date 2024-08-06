class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);

        for(auto c : word){
            freq[c - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());
        for(auto it: freq)cout<<it<<" ";

        int ans =0;

        for(int i=0; i<freq.size(); i++){
            if(freq[i] ==0 )break;
            ans += (i/8 + 1) * freq[i];
        }

        return ans;
    }
};