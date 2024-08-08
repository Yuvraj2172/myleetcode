class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;

        int r = rStart, c = cStart;
        int dir[4][2] = {{0,1}, {1,0}, {0,-1},{-1,0}};

        ans.push_back({r,c});
        int dirrec = 0;
        int moves = 0;
        while(ans.size() < rows* cols){
            if(dirrec %2==0){
                moves++;
            }

            for(int i=0; i<moves; i++){
                r += dir[dirrec][0];
                c += dir[dirrec][1];

                if(r>=0 && r < rows && c>=0 && c < cols){
                    ans.push_back({r,c});
                }
            }
            dirrec = (dirrec + 1)%4;
        }   

        return ans;
    }
};