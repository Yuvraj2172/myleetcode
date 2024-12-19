class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        return count_if(arr.begin(), arr.end(), 
            [i=0, diff=0](int x) mutable{
            diff+=x-(i++);
            return diff==0;
        });
    }
};