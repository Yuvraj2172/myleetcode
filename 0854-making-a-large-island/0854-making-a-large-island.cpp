class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> labels(n,vector<int>(n,0));
        unordered_map<int,int> mp;

        int label =1;
        int ans =0;
        int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        for(int i=0; i<n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && labels[i][j]== 0){
                    int size =0 ;
                    vector<pair<int,int>> st;
                    st.push_back({i,j});
                    labels[i][j] = label;
                    while(!st.empty()){
                        size++;
                        auto [x,y] = st.back();
                        st.pop_back();
                        for(auto [dx,dy] : dir){
                            int nx = x + dx, ny = y + dy;
                            if(nx >=0 && nx < n && ny >=0 && ny < n && grid[nx][ny] == 1 && labels[nx][ny] == 0){
                                labels[nx][ny] = label;
                                st.push_back({nx,ny});
                            } 
                        }
                    }
                    mp[label] = size;
                    ans = max(ans, size);
                    label++;
                }
            }
        }
        for(int i=0; i< n; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> neighborlabels;
                    int total = 1;
                    for(auto [dx, dy] : dir){
                        int nx = i + dx, ny = j + dy;
                        if(nx >=0 && nx < n && ny >=0 && ny < n && grid[nx][ny] == 1){
                            int lbl = labels[nx][ny];
                            if(neighborlabels.find(lbl) == neighborlabels.end()){
                                neighborlabels.insert(lbl);
                                total+=mp[lbl];
                            }
                        }
                    }

                    ans = max(ans, total);
                }
                 
            }
        }
        return ans;

    }
};


       