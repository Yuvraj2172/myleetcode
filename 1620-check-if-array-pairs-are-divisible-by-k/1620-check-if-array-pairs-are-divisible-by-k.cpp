class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> f(k,0);

        for(auto it : arr){
            int rem = it % k;
            if(rem < 0)rem += k;
            f[rem]++;
        }        

        if(f[0] % 2 !=0)return 0;

        for(int i =1; i<=k/2; i++){
            if(f[i] != f[k-i])return 0;
        }
        return 1;

    }
};