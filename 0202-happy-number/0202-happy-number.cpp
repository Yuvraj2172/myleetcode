class Solution {
public:
    int nextNumber(int n){
        int newNumber =0;
        while(n!=0){
            int num = n%10;
            newNumber+=(num*num);
            n/=10;
        }
        return newNumber;
    }
    bool isHappy(int n) {
        int slowNumber=n;
        int fastNumber = nextNumber(n);
        while(fastNumber!=1 && slowNumber!= fastNumber){
            slowNumber = nextNumber(slowNumber);
            fastNumber = nextNumber(nextNumber(fastNumber));
        }
        return fastNumber == 1;
    }
};