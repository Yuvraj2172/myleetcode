class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, vector<int>> m;
        unordered_map<int, vector<int>> mrow;
        unordered_map<int, vector<int>> mcol;
        int count = 0;
        for(int i=0; i<9; i++){
            if(i<3)count=0;
            else if(i>2 && i <6)count = 3;
            else if(i>=6)count = 6;
            for(int j=0; j<9; j++){
                if(board[i][j] >= '1' && board[i][j]<='9'){
                    mrow[i].push_back(board[i][j] - '0');
                    mcol[j].push_back(board[i][j] - '0');
                    m[count + j/3].push_back(board[i][j]- '0');
                }
            }
            count = 0;
        }
        for(auto col : mcol){
            vector<int> temp(10,0);
            for(auto it : col.second){
                temp[it]++;
            }
            for(auto it : temp)if(it > 1)return false;
        }
        for(auto row : mrow){
            vector<int> temp(10,0);
            for(auto it : row.second){
            temp[it]++;
            }
            for(auto it : temp)if(it>1)return false;
        }
        for(auto p : m){
            vector<int> temp(10,0);
            for(auto it : p.second){
                temp[it]++;
            }
            for(auto it : temp)if(it > 1)return false;
        }
        return true;
    }
};