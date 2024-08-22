class Solution {
public:
    int findComplement(int num) {
        vector<int> v;
        while(num){
            int last = num%2;
            v.push_back(last);

            num /=2;
        }
        for(int i=0; i<v.size(); i++){
            if(v[i] == 0)v[i] = 1;
            else v[i] = 0;
        }

        num =0;
        int i=0;
        for(auto it : v){
            num = num + pow(2,i) * it;
            i++;
        }
        return num;
    }
};