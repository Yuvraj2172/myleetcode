class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int e(0), o(0);
        for(int i=0; i<position.size(); i++){
            if(position[i]%2)o+=1;
            else e+=1;
        }
        return min(o,e);
    }
};