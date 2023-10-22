class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
        if(s.size()==1)
        {
            return false;
        }
        set<int,greater<int>>divs;
        int n=s.size();
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                divs.insert(n/i);
                divs.insert(i);
            }
        }
        divs.insert(1);
        n=s.size();
        for(auto i:divs)
        {
            int j=0;
            while(j+2*i<=n&&s.substr(j,i)==s.substr(j+i,i))
            {
                j+=i;
            }
            if(j==n-i)
            {
                return true;
            }
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    divs.erase(j);
                    divs.erase(i/j);
                }
            }
        }
        return false;
    }
};