class Solution {
public:
    int maxAscendingSum(vector<int>& a) {
        int ans =0 ;
        int n = a.size();
        int temp =0;
        for(int i =0; i < n - 1; i++){
            if(a[i] < a[i+1]){
                temp+= a[i];
            }else{
                temp += a[i];
                ans = max(ans, temp);
                temp = 0;
            }
        }
        temp += a[n-1];
        return max(ans, temp);
    }
};