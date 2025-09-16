class Solution {
public:

int gcd(long long  a,long long b){
 if(b==0) return a;
 return gcd(b,a%b);
}
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        vector<int>ans;
    //   cout<<gcd(5,10)<< " "<<gcd(18,10);
        for(int i=0;i<nums.size();i++){
            long long  temp=nums[i];
            while(!st.empty() && gcd(st.top(),temp)!=1){
                temp=(1LL*st.top()*temp)/gcd(st.top(),temp);
                st.pop();
            }
            st.push(temp);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};