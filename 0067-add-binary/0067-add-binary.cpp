class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size()-1 , lb = b.size()-1;
        string s;
        int sum=0, carry =0;
        while(la>=0 || lb>=0 || carry!=0){
            sum = carry;
             if(la>=0){
              sum += a[la] - '0';
                 la--;
               }
            if(lb>=0){
            sum+= b[lb] - '0';
                lb--;
            }
            s += to_string(sum%2);
            carry = sum/2;
        }
        reverse(s.begin() , s.end());
        return s;
    }
};