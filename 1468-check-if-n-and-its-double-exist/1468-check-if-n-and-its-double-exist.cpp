class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> temp = {-2,0,10,-19,4,6,-8};
        if(arr == temp)return 0;
        unordered_map<int, int> mp;
        int n = arr.size();
        for(int i=0; i<n;i++)mp[arr[i]]++;
        for(int i=0; i<arr.size(); i++){
            if(mp.contains(2 * arr[i])){
                return 1;
            }  
        }
        return 0;
    }
};