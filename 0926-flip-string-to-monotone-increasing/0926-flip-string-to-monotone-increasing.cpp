class Solution {
public:
    int minFlipsMonoIncr(string s) {
        if(s.size()==0)return 0;
        int ones = 0;
        int flips =0;
        for( auto ch : s ){
            if(ch=='0'){
                if(ones!=0){
                    flips++;
                }
            }else{
                ones++;
            }
            if(flips> ones){
                flips = ones;
            }
        }
        return flips;
    }
};