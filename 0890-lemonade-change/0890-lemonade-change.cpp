class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        int c5 =0, c10=0;
        int n= arr.size();
        for(int i=0; i < n; i++){
            if(arr[i] == 5)c5++;
            else if(arr[i] == 10){
                if(c5>0){
                    c5-=1;
                    c10++;
                }else return false;
            }
            else if(arr[i] == 20){
                if(c10 >0 && c5 >0){
                    c10-=1;
                    c5-=1;
                }
                else if(c5>=3){
                    c5-=3;
                }else return false;
            }
        }
        return true;
    }
};