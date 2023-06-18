class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int g=0 , c=0;
        for(int i=0 ; i < n;i++){
            g+= gas[i];
            c+=cost[i];
        }
        if(g < c)return -1;
        int total =0;
        int res =0;
        for(int i=0 ; i < n;i++){
            int diff = gas[i] - cost[i];
            total += diff;
            if(total < 0){
                total=0;
                res = i+1;
            }
        }
        return res;
    }
};