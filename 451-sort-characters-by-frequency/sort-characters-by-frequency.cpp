class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        string ans = "";
        for(auto ch : s){
            mp[ch]++;
        }
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        while(!pq.empty()){
            pair<int,char> cur = pq.top();
            pq.pop();
            while(cur.first--)ans += cur.second;
        }
        return ans;
    }
};