class Solution {
public:
    int findPar(int val, vector<int>& par){
        if(par[val] == val)return val;
        return par[val] = findPar(par[val], par);
    }
    bool Union(int a, int b, vector<int>& par, vector<int>& size){
        int par1 = findPar(a,par);
        int par2 = findPar(b,par);
        if(par1 == par2)return false;
        if(size[par1] > size[par2])par[par2] = par1;
        else if(size[par2] > size[par1])par[par1] = par2;
        else {
            par[par2] =par1;
            size[par1]++;
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for(int i=0; i<n;i++){
            for(int j = i+1; j<n;j++){
                vector<int> temp;
                int dist = abs(points[i][0] - points[j][0]) + 
                            abs(points[i][1] - points[j][1]);
                temp.push_back(dist); temp.push_back(i); temp.push_back(j);
                edges.push_back(temp);
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> par(n,-1), size(n,1);
        for(int i=0; i<n;i++)par[i] = i;
        int ans =0;
        for(auto & e : edges){
            bool flag = Union(e[1], e[2], par,size);
            if(flag)ans+= e[0];
        }
        return ans;
    }
};