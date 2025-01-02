class Solution {
public:

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n+1, 0);

        unordered_set<char> vow = {'a', 'e', 'i','o','u'};

        for(int i=0; i<n;i++){
            pref[i+1] = pref[i];
            if(vow.count(words[i].front()) && 
                vow.count(words[i].back())){
                    pref[i+1]++;
            }
            
        }

        vector<int> ans;

        for(auto it : queries){
            int l = it[0];
            int r = it[1];

            ans.push_back(pref[r+1] - pref[l]);

        }

        return ans;
    }
};

