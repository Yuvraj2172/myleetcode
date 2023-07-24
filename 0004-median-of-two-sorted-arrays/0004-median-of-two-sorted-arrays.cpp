class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int> v;
        int i=0,j=0;
        int n = a.size() , m = b.size();
        while(i< n && j <m){
            if(a[i]<b[j]){
                v.push_back(a[i++]);
            }
            else {
                v.push_back(b[j++]);
            }
        }
        while(i<n){
            v.push_back(a[i++]);
        }
        while(j<m){
            v.push_back(b[j++]);
        }
        return (n+m)%2==0 ? (double)(v[(n+m)/2] + v[(n+m)/2 -1])/2 : v[(n+m)/2];
    }
};