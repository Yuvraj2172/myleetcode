class Solution {
public:
    int countPartitions(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int s = accumulate(arr.begin() ,arr.end(), 0);
        int ls =0;
        for(int i =0; i < n -1; i++){
            ls += arr[i];
            int rs = s - ls;
            if((ls - rs )% 2 ==0)ans+=1;
        }
        return ans;
    }
};