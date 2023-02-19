class Solution {
public:
    int mySqrt(int x) {
        long long int left=0,right=100000;
        long long int mid=(left+right)/2;
        while(true)
        {
            long long int temp=mid;
            if (mid*mid>x) right=mid+1;else left=mid;
            mid=(left+right)/2;
            if (temp==mid) break;
        }
            
        return left;
    }
};