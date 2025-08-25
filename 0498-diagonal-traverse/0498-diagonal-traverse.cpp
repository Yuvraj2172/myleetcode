class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<int> ans(m*n);

        int row = 0, col = 0;
        for (int i = 0; i < m*n; i++) {
            ans[i] = arr[row][col];

            if (i == m*n - 1) break;  // ✅ stop before stepping out of bounds

            if ((row + col) & 1) { // odd diagonal → going down-left
                if (row == m-1) {
                    col++;
                } else if (col == 0) {
                    row++;
                } else {
                    row++;
                    col--;
                }
            } else { // even diagonal → going up-right
                if (col == n-1) {
                    row++;
                } else if (row == 0) {
                    col++;
                } else {
                    row--;
                    col++;
                }
            }
        }
        return ans;
    }
};
