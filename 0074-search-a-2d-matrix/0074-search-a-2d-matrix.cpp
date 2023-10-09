class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n = matrix.size(), m = matrix[0].size();
       int left =0, right = m*n -1;
       while(left <= right){
           int mid = left + (right - left)/2;
           int midval = matrix[mid/m][mid%m];
           if(midval == target)return 1;
           else if(midval < target)left=mid+1;
           else right = mid-1;
       }
        return 0;
    }
};