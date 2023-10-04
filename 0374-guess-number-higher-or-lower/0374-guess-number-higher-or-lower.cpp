class Solution {
public:
    int guessNumber(int n) {
        int start =1, end = n;
        int ans = 0;
        while(start <= end){
            long long int mid = start + (end - start)/2;
            int g = guess(mid);
            if(g==0){
                return mid;
            }
            else if(g == -1){
                end = mid-1;
            }
            else start = mid+1;
        }
        return -1;
    }
};