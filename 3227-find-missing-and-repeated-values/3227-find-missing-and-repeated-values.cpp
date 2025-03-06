class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        unordered_set<int> st;
        int dup = -1, miss= -1;
        for(int i=0; i < arr.size(); i++){
            for(int j =0; j < arr.size(); j++){
                if(st.find(arr[i][j])!=st.end()){
                    dup = arr[i][j];
                    continue;
                }
                st.insert(arr[i][j]);
            }
        }
        for(int i = 1; i<=pow(arr.size(),2); i++){
            if(miss == -1 && st.find(i)==st.end()){
                miss = i;
                break;
            }  
        }
        return {dup,miss};
    }
};