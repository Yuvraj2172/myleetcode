class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        map<int,int> mp;


        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : arr)pq.push(it);

        int i =1;
        while(!pq.empty()){
            int ele = pq.top(); pq.pop();
            if(mp.contains(ele)){
                mp[ele] = min(mp[ele], i);
                // i++;
            }else {
                mp[ele] = i;
                i++;
            }
        }
        for(int i=0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }

        
        return arr;
    }
};