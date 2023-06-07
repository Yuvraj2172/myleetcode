class Solution {
public:
    bool helper(vector<int>&arr, int start , int len){
        if(start<0 || start>= len)return false;
        if(arr[start]<0)return false;
        if(arr[start]==0)return true;
        arr[start] = -arr[start];
        return helper(arr, start + arr[start], len) or helper(arr, start - arr[start], len);
    }
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        return helper(arr , start,  len);
    }
};