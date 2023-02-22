class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        list<int> ans;
        int carry =1;   
        int sum=0;
        for(int i=digits.size()-1;i>=0;i--){
            sum = carry;
            sum = carry + digits[i];
            ans.push_front(sum%10);
            carry = sum/10;
        }
        if(carry!=0)ans.push_front(carry%10);
        digits.clear();
        for(auto it= ans.begin(); it!=ans.end();it++){
            digits.push_back(*it);
        }
        return digits;
    }
};