//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int finally=0;
        int frequencyZero=0;
        for(int i=0;i<n;i++){
            if (arr[i]==0){
                frequencyZero++;
                if(i>0 && arr[i-1]!=0) finally++;
            }
        }
        if(arr[n-1]!=0) finally++;
        if(frequencyZero==n) return 0;
        if(frequencyZero==0) return -1;
        return finally;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends