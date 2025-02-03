class Solution {
public:
    int helper(vector<int>& arr, int target, int l, int h){
        if(l > h)return -1;
        int mid = l + (h - l)/2;
        if(arr[mid] == target)return mid;
        if(arr[mid] < target)return helper(arr, target, mid + 1, h);
        return helper(arr, target, l, mid-1);
    }
    int search(vector<int>& arr, int target) {
        return helper(arr, target, 0, arr.size() - 1)  ;
    }
};