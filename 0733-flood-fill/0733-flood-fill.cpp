class Solution {
public:
    void dfs(int sr , int sc , vector<vector<int>>& img , int incol,  int newcol, int row , int col){
        if(sr<0 or sr>= row or sc<0 or sc>=col or img[sr][sc]!= incol  or img[sr][sc] == newcol)return;
        img[sr][sc] = newcol;
        dfs(sr-1 , sc , img , incol, newcol , row , col);
        dfs(sr+1 , sc , img , incol , newcol , row , col);
        dfs(sr , sc-1 , img , incol , newcol , row , col);
        dfs(sr , sc+1 , img , incol , newcol , row , col);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int incolor = image[sr][sc];
        dfs(sr , sc , image , incolor , color, n,m);
        return image;
    }
};