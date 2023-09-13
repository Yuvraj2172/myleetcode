class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1)return 1;
        vector<int> candies(n,1);
        for(int i=0; i <n-1;i++){
          if(ratings[i+1] > ratings[i])candies[i+1] = candies[i]+1;
        }
        for(int i = n-1; i>0; i--){
          if(ratings[i-1]> ratings[i] && candies[i-1] <= candies[i])
          candies[i-1] = candies[i] + 1;
        }
        return accumulate(candies.begin(), candies.end(), 0LL);
    }
};