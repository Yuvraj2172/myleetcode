class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto it : s)mp[it]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto it : mp)pq.push({it.second, it.first});
        
        string ans;
        
        while(pq.size()>=2){
            auto it1 = pq.top(); pq.pop();
            auto it2 = pq.top(); pq.pop();
            ans.push_back(it1.second); ans.push_back(it2.second);
            if(it1.first -1 > 0 )pq.push({it1.first - 1 , it1.second});
            if(it2.first - 1 > 0)pq.push({it2.first - 1, it2.second});
        }
        if(!pq.empty()){
            auto it = pq.top();
            int fq = it.first;
            char ch = it.second;
            if(fq > 1)return "";
            ans.push_back(ch);
        }
        return ans;
    }
};