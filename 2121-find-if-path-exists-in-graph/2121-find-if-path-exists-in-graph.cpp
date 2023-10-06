class Solution {
public:
        unordered_set<int> travelled;
        unordered_map<int,vector<int>> mp;
    bool validPath(int n, vector<vector<int>>& edges,
     int source, int destination) {
        for(auto it : edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        dfs(source);
        if(travelled.find(destination)!= travelled.end())return 1;
        return 0;
    }
    void dfs(int source){
        if(travelled.find(source)!= travelled.end())return;
        travelled.insert(source);
        for(auto it : mp[source])dfs(it);
    }
};