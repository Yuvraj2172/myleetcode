class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(auto it : arr1){
            while(it){
                st.insert(it);
                it/=10;
            }
        }
        int ans = 0;
        
        for(auto it : arr2){
            while(it){
                if(st.find(it)!=st.end()){
                    ans = max(ans, (int)log10(it) + 1);
                }
                it/=10;
            }
        }

        return ans;
    }
};