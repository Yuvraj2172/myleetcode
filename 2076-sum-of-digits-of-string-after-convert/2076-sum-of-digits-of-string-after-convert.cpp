class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        int n = s.size();
        for(int i=0; i<n;i++){
            char ch = s[i];
            int c = ch - 96;
            num += to_string(c);
        }
        // cout<<num;

        long long sum = 0;
        int i=0;
        while(i<k){
            sum=0;
            for(int j=0; j<num.size(); j++){
                sum+= (num[j] - '0');
            }
            num = to_string(sum);
            cout<<num<<" ";
            i++;
        }
        
        return sum;
    }
};