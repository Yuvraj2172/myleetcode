class Solution {
public:
    int findComplement(int num) {
        if(num==0)return 1;
        if(num==1)return 0;
        int b =0;
        vector<int> v;
        while(num!=0){
             v.push_back(!(num%2));
            num/=2;
        }
        // for(auto it : v)cout<<it<<" ";
        for(int i=0;i<v.size();i++){
            b = b + v[i]*pow(2,i);
        }
        return b;
    }
};