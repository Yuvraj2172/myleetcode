class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int l =0, h = n-1;
        vector<int> res(2,-1);
        while(l <= h){
            int mid = (l + h)>>1;
            if(arr[mid]>= target){
                if(arr[mid] == target)res[0] = mid;
                h = mid -1;
            }else{
                l = mid + 1;
            }
        }
        l = 0, h = n-1;
        while(l <= h){
            int mid = (l + h)>>1;
            if(arr[mid]<= target){
                if(arr[mid] == target)res[1] = mid;
                l = mid +1;
            }else{
                h = mid - 1;
            }
        }
        return res;
    }
};