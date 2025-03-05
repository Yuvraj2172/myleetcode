class Solution {
public:
    long long coloredCells(int n) {
       return 1 + 1LL * 2 * (n-1) * n; 
    }
};