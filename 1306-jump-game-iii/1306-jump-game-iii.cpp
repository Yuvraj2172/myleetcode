class Solution {
public:
    bool helper(vector<int>& arr , int start ,int len,vector<int>&vis){
        if(start<0 || start >= len)return false;
        if(vis[start]==2)return false;
        if(arr[start] == 0)return true;
        vis[start]+=1;
        bool forward = helper(arr, start + arr[start], len,vis);
        bool backward = helper(arr, start - arr[start], len,vis);
        return forward || backward;
    }
    bool canReach(vector<int>& arr, int start) {
        // cout<<arr[0] +12;
        int len = arr.size();
        vector<int> vis(len , 0);
        return helper(arr, start, len,vis);
        // return 1;
    }
};