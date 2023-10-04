class Solution {
public:
    int firstBadVersion(int n) {
        int start =0, end = n;
        int ans = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            bool f = isBadVersion(mid);
            if(f){
                ans = mid;
                end = mid - 1; continue;
            }
            start = mid + 1;
        }
        return ans;
    }
};