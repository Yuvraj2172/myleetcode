class Solution {
public:
    string multiply(string a, string b) {
        if( a == "0" || b == "0" )return "0";
        int n = a.size(), m = b.size();
        string res(n+m,'0');
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int num = (a[i] - '0') * (b[j] - '0') + (res[i+j+1] - '0');
                res[i+j+1] = num%10+'0';
                res[i + j] += num/10;
            }
        }
        int i=0; while(i < res.size() && res[i] == '0')i++;
        return res.substr(i);
    }
};