class Solution {
public:
   vector<int>bits; 
   void updateBit(int j,vector<int>&nums,bool ch){
    for(int i=0;i<32;i++){
        if((nums[j]&(1<<i)) && ch) bits[i]++;
        else if((nums[j]&(1<<i)) &&!ch)bits[i]--;
    }
   }


    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,ans=INT_MAX;
          bits.assign(32, 0);
        while(j<n){
           updateBit(j,nums,1);
            long num=0;
           for(int p=0;p<32;p++){
            if(bits[p])num+=(long) pow(2,p);
           }
            while(num>=k && i<=j){
                ans=min(ans,j-i+1);
                updateBit(i,nums,0);
                num=0;
              for(int p=0;p<32;p++){
             if(bits[p])num+=(long) pow(2,p);
            }
            i++;
           }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};