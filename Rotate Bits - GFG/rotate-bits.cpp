//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            int left =0 , right =0 , bits[16], sum;
            int i,j;
            d = d %16;
            for(i=0; i<16;i++){
                bits[i] = (n%2);
                n/=2;
            }
            sum = 1;
            for(i = (16 -d)%16, j=0; j < 16; j++, i = (i+1)%16){
                if(bits[i] == 1)left += sum;
                sum*=2;
            }
            sum = 1;
            for( i = d , j = 0; j< 16; j++, i = (i+1)%16){
                if(bits[i] == 1)right += sum;
                sum*=2;
            }
            return {left,right};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends