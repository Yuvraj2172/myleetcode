class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowStart =0, rowEnd = matrix.size()-1 , colStart =0 , colEnd  = matrix[0].size()-1;
        int c =0;
        vector<int> ans;
        int m = matrix.size() , n= matrix[0].size();
        while(c< m*n){
            for(int i = colStart ; i<=colEnd;i++){
                ans.push_back(matrix[rowStart][i]);
                c++;
            }
            rowStart+=1;
            for(int i = rowStart ; i <= rowEnd ; i++){
                ans.push_back(matrix[i][colEnd]);
                c++;
            }
            colEnd-=1;
            if(rowStart<= rowEnd){
                for(int i =colEnd;i>=colStart;i--){
                    ans.push_back(matrix[rowEnd][i]);
                    c++;
                }
                rowEnd-=1;
            }
            if(colStart<= colEnd){
                for(int i = rowEnd ; i>= rowStart; i--){
                    ans.push_back(matrix[i][colStart]);
                    c++;
                }
                colStart+=1;
            }       
        }
        return ans;
    }
};