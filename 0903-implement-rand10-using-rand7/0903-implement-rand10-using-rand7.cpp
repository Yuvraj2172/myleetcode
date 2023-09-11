class Solution {
public:
    int rand10() {
        int rand40 = 1e9+7;
        while(rand40 >= 40){
            rand40= (rand7()-1)*7 + rand7() - 1;
        }
        return rand40%10 + 1;
    }
};