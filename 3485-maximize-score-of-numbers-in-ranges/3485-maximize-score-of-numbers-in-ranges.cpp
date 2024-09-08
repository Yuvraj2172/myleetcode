class Solution {
public:

    bool check(vector<int>& start, int d, int gap){
        int lastnum = start[0];

        for(int i=1; i<start.size(); i++){
            if(lastnum + gap > start[i] + d)return false;
            lastnum = max(start[i], lastnum + gap);
        }
        return 1;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(begin(start), end(start));

        int left = 0, right = INT_MAX;
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(check(start, d, mid)){
                ans = mid;
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return ans;
    }
};