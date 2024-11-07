class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxSize = 0;

        
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;

            
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }

            
            maxSize = max(maxSize, count);
        }

        return maxSize;
    }
};