class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right)>>1;
            if(arr[mid] == target){
                return 1;
            }

            if(arr[left] == arr[mid] && arr[mid] == arr[right]){
                left++;
                right--;
                continue;
            }
            if(arr[left] <= arr[mid]){
                
                if(arr[left] <= target && target <= arr[mid]){
                    right = mid-1;
                }
                else{
                    left = mid + 1;
                }

            }else{

                if(arr[mid] <= target && target <= arr[right]){
                    left = mid +1;
                }
                else{
                    right = mid -1;
                }

            }
        }
        return 0;

    }
};