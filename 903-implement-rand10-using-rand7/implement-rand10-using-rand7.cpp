class Solution {
public:
    int rand10() {
        while(1){
            int row = 7*(rand7()-1);
            int col = rand7();
            int num = row + col;
            if(num <= 40){
                return (num-1)%10+ 1 ;
            }
        }
        return 0;
    }
};