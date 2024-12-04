class Solution {
public:
    bool canMakeSubsequence(string a, string b) {
        int n = a.size(), m = b.size();
        int i=0, j =0;

        while(i < n && j < m){
            if(a[i] == b[j] ||
            ((a[i] + 1)%26== (b[j]%26))){
                
                j++;
            }
            if(j == m)return 1;
            i++;
        }

        return j == m;

    }
};