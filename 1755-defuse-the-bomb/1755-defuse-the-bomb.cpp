class Solution {
public:
    vector<int> decrypt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans(n,0);
        if(k == 0)return ans;

        for(int i=0; i<n;i++){
            arr.push_back(arr[i]);
        }

        if(k  > 0){
            for(int i=0; i<n;i++){
                int sum = 0;
                for(int j = 0; j < k; j++){
                    sum += arr[i + j + 1];
                }
                ans[i] = sum;
            }

            return ans;
        }
       int ind = n-1;
        for(int i=2*n -1;i >=n;i--){
        	
                int sum = 0;
               
                for(int j = abs(k); j > 0; j--){
                    sum += arr[i - j  ];

                   
                }
                 
                ans[ind--] = sum;
                // cout<<sum<<" ";
            }

            return ans;

    }
};