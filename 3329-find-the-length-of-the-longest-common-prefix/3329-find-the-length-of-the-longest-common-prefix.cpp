class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> st;

        for(auto num : arr1){
            while(num){
                st.insert(num);
                num/=10;
            }
        }

        int ans = 0;

        for(auto num : arr2){
            while(num){
                if(st.find(num)!=st.end()){
                    ans  = max(ans, (int)log10(num) + 1);
                }
                num/=10;
            }
        }
        return ans;
    }
};