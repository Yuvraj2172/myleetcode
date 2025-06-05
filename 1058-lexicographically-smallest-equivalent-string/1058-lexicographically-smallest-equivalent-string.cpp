class Solution {
public:
    vector<int> headchar;
    int find(int x){
        if(headchar[x] == -1){
            return x;
        }
        return headchar[x] = find(headchar[x]);
    }
    void Union(int x, int y){
        int parentx = find(x), parenty = find(y);
        if(parentx == parenty)return;
        headchar[max(parentx, parenty)] = min(parentx, parenty);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        headchar.resize(26,-1);
        for(int i=0; i < s1.size(); i++){
            Union(s1[i] - 'a', s2[i] - 'a');
        } 
        for(int i=0; i < baseStr.size(); i++){
            baseStr[i] = find(baseStr[i] - 'a') + 'a';
        }  
        return baseStr;
    }
};