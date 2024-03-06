class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1, right = 0;
        while(left >=0 && right < n){
            if(nums1[left] > nums2[right]){
                swap(nums1[left--], nums2[right++]);
            }
            else {
                break;
            }
        }
        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(), nums2.end());
        for(int j = 0, i=m; j<n;j++,i++){
            nums1[i] = nums2[j];
        }
    }
};