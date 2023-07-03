class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        
        if (s == goal) {
            vector<int> count(26, 0);
            
            for (int i = 0; i < s.length(); i++) {
                int c = s[i] - 'a';
                count[c]++;
                if (count[c] == 2)
                    return true;
            }
            
            return false;
        }
        
        int index1 = -1;
        int index2 = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (index1 == -1)
                    index1 = i;
                else if (index2 == -1)
                    index2 = i;
                else
                    return false;
            }
        }
        
        if (index2 == -1)
            return false;
        
        return (s[index1] == goal[index2] && s[index2] == goal[index1]);
    }
};