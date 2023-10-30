class Solution {
public:
    static bool compare(int a, int b){
        int na= __builtin_popcount(a);
        int nb = __builtin_popcount(b);
        if(na == nb)return a<b;
        return na < nb;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};