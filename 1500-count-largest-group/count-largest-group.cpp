class Solution {
public:
    int countLargestGroup(int n) {
       map<int, vector<int>> mp;
       for(int i=1; i<=n;i++){
           int sum =0;
           int temp = i;
           while(temp!=0){
               sum += (temp%10);
               temp/=10;
           }
           mp[sum].push_back(i);
       } 
       int ans =0;
       int ms = 0;
       for(auto it : mp){
           if(it.second.size()> ms)ms = it.second.size();
       }
       for(auto it : mp){
           if(it.second.size() == ms)ans++;
       }
       return ans;
    }
};