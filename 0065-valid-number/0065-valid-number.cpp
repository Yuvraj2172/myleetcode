class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool digitf=0, ef=0, decif=0;
        int signC=0;
        for(int i=0;i<n;i++){
            if(isdigit(s[i]))digitf=1;
            else if(s[i]=='+' || s[i]=='-'){
                if(signC==2)return 0;
                if(i>0 && (s[i-1]!='e' && s[i-1]!='E'))return 0;
                if(i==n-1)return 0;
                signC+=1;
            }
            else if(s[i]=='.'){
                if(ef || decif)return 0;
                if(i==n-1 && !digitf)return 0;
                decif=1;
            }
            else if(s[i]=='e' || s[i]=='E'){
                if(ef || i==n-1 || !digitf)return 0;
                ef=1;
            }
            else return 0;
        }
        return 1;
    }
};