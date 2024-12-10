class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int low=0,high=n-1;
        while(low<high){
            int mid = (low+high)/2;
            if(check(s,mid)) low = mid+1;
            else high = mid;
        }
        return low-1;
    }
    bool check(string s,int len){
        int count = 1;
        vector<int> occ(26,0);
        char prev = ',';
        for(int i=0;i<s.size();i++){
            if(s[i]==prev){
                count++;
            }
            else{
                count = 1;
                prev = s[i];
            }
            if(count>=len && ++occ[s[i]-'a']>=3){
                return true;
            }
        }
        return false;
    }
};