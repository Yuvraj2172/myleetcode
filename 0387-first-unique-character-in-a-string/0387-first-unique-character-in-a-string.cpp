class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
        int ans = -1;
        for(int i=0; i<s.length(); i++){
            int index = s[i]-'a';
            arr[index]++;
        }
        for(int i=0;i<s.length();i++){
            if(arr[s[i]-'a'] == 1) return i; 
        }
        return ans;
    }
};