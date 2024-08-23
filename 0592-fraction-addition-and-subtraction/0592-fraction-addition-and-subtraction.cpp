class Solution {
public:
    string fractionAddition(string s) {
        int numerator = 0, denominator = 1;
        int i=0, n = s.size();   

        

        while(i<n){
            int sign = 1;
            if(s[i] == '+' || s[i] == '-'){
                if(s[i] == '-')sign = -1;
                   i++;
            }
         


        int num = 0;

        while(i<n && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
            i++;
        }
        num *= sign;
        i++;

        int den = 0;
        while(i<n && isdigit(s[i])){
            den = den * 10 + (s[i] - '0');
            i++;
        }

        numerator = numerator * den + denominator * num;
        denominator = denominator * den;

        int hcf = gcd(abs(numerator), denominator);
        numerator = numerator / hcf;
        denominator = denominator / hcf;
        }

        return to_string(numerator) + '/'  +to_string(denominator);
    }
};