//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int helper(int n, int arr[], int sum, vector<vector<int>>& dp){
        if(n<0)return sum==0;
        if(n!=-1 && sum==0)return 1;
        if(dp[n][sum]!=-1)return dp[n][sum];
        bool take= false;
        bool nontake= false;
        if(arr[n]<=sum){
            take = helper(n-1, arr, sum - arr[n], dp) + helper(n-1, arr, sum , dp);
        }
        else{
            nontake = helper(n-1, arr, sum, dp);
        }
        return dp[n][sum] = take + nontake;
    }
    int equalPartition(int n, int arr[])
    {
       int sum =0;
       for(int i=0; i<n;i++)sum+=arr[i];
       if(sum&1)return 0;
       sum=sum>>1;
       vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
       return helper(n-1, arr, sum ,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends