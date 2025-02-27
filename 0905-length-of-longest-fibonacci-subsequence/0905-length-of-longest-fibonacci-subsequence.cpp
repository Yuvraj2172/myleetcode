class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        int ans = 0;
        int n = arr.size();
        for(int i=0; i < n; i++){
            for(int j = i +1 ; j < n; j++){
                int a = arr[i];
                int b = arr[j];
                int c =2;
                while(st.count(a + b)){
                    int x = b;
                    b = b + a;
                    a = x;
                    c++;
                }
                ans = max(ans, c);
            }
        }
        return ans > 2 ? ans : 0;
    }
};