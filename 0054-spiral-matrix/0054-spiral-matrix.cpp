class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n  =matrix.size() , m = matrix[0].size();
        int rowStart =0 , colStart =0 , rowEnd = n-1 , colEnd = m-1;
        int c=0;
        while(c< m*n){
            for(int i= colStart ; i <= colEnd;i++){
                ans.push_back(matrix[rowStart][i]);
                c++;
            }
            rowStart++;
            for(int i = rowStart ;i <= rowEnd ; i ++ ){
                ans.push_back(matrix[i][colEnd]);
                c++;
            } colEnd--;
            if(rowStart <= rowEnd){
                for(int i = colEnd ; i>= colStart ; i--){
                    ans.push_back(matrix[rowEnd][i]);
                    c++;
                }
                rowEnd--;
            }
           
             if(colStart <= colEnd){
                for(int i= rowEnd ; i>= rowStart ; i--){
                    ans.push_back(matrix[i][colStart]);
                    c++;
                }
                colStart++;
            }
            
           
        }
        return ans;
    }
};