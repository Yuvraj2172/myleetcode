class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(auto it : s){
            freq[it - 'a']++;
        }
        string ans = "";
        priority_queue<pair<char, int>> pq;
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                pq.push({i + 'a', freq[i]});
            }
        }

        while(!pq.empty()){
            auto [ch, count] = pq.top(); 
            pq.pop();

            int use = min(repeatLimit, count);

            ans.append(use, ch);

            count -= use;
            if(count > 0){
                if(pq.empty())break;
                auto [nextchar, nextcount] = pq.top();
                pq.pop();

                ans += nextchar;
                nextcount--;
                if(nextcount >0){
                    pq.push({nextchar, nextcount});
                }
                pq.push({ch, count});    
               
            }

        }
        return ans;
    }
};