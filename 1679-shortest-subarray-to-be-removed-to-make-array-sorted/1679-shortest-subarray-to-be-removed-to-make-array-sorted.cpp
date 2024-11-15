class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left =0 ;
        int n = arr.size();
        int right = n-1;

        while(left + 1 < n  && arr[left] <= arr[left+ 1] ){
            left+=1;
        }

        if(left == n-1)return 0;

        while(right > 0 && arr[right] >= arr[right-1]){
            right -=1;
        }

        int ans = min( n - left -1, right);
        int i = 0; 
        int j = right;

        while(i <= left && j < n){
            if(arr[i] <= arr[j]){
                ans = min(ans, j - i -1);
                i+=1;
            }
            else{
                j++;
            }
        } 
        return ans;
    }
};