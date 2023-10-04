class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()); 
        vector<int> s;
        for(set<int>::iterator itr = s1.begin(); itr!=s1.end(); itr++){
            for(set<int>::iterator itr2 = s2.begin(); itr2 != s2.end(); itr2++){
                if(*itr == *itr2){
                    s.push_back(*itr2);
                }
            }
        }
        return s;
    }
};