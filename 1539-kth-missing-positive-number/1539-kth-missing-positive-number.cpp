class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l =0;
        int h = arr.size();
        while(l<h){
            int m = l + (h-l)/2;
            if(arr[m] - (m +1)>=k){
                h = m;
            }else {
                l = m+1;
            }
        }
        return l + k;
    }
};