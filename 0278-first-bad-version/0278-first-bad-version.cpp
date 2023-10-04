class Solution {
public:
    int firstBadVersion(int n) {
        int start =0;
        int end = n;
        int res=0;
        while(start <= end){
            int mid = start + (end - start)/2;
            bool ans  = isBadVersion(mid);
            if(ans){
                res = mid;
                end = mid-1; continue;
            }
            start = mid+1;
        }
        return res;
    }
};