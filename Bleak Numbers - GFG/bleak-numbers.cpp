//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int count(int x){
        int ans(0);
        while(x!=0){
            int l = x%2;
            if(l==1)ans++;
            x/=2;
        }
        return ans;
    }
	int is_bleak(int n)
	{
	    for(int i = n-1; i>=max(1,n-32); i--){
	        if(n==i + count(i))return 0;
	    }
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends