//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool pall(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int ways(int i, int n, string& s, vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans = INT_MAX;
        for(int j = i; j<n;j++){
            if(pall(i,j,s)){
                int temp   = 1 + ways(j+1,n,s,dp);
                ans  = min(ans, temp);
            }
        }
        return dp[i]= ans;
    }
    int palindromicPartition(string s)
    {   int n = s.length();
        vector<int> dp(n,-1);
        return ways(0,n,s,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends