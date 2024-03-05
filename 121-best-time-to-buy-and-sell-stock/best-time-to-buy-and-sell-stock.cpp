class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int min = 1e9+7;
        int maxi = 0;
        int n = arr.size();
        for(int i=0; i<n;i++){
            if(arr[i] < min){
                min = arr[i];
             
            }
               maxi = max(maxi,arr[i] - min);
        }
        return maxi;
    }
};