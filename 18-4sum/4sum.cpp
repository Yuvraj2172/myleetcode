class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Sort the input vector to simplify the search process
        sort(nums.begin(), nums.end());
        
        // Vector to store the resulting quadruplets
        vector<vector<int>> temp;
        
        // Loop through each element in the sorted vector
        for (int i = 0; i < n; i++) {
            // Skip duplicates of the first element to avoid duplicate quadruplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            // Loop through each element after the first element
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates of the second element to avoid duplicate quadruplets
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                // Pointers for the third and fourth elements of the quadruplet
                int k = j + 1;
                int l = n - 1;
                
                // While the third pointer is less than the fourth pointer
                while (k < l) {
                    // Calculate the sum of the current quadruplet
                    //long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];

                    
                    // If the sum equals the target, add the quadruplet to the result vector
                    if (sum == target) {
                        vector<int> ans = {nums[i], nums[j], nums[k], nums[l]};
                        temp.push_back(ans);
                        
                        // Move the third pointer to the right and the fourth pointer to the left
                        k++;
                        l--;
                        
                        // Skip duplicates of the third and fourth elements
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    } 
                    // If the sum is less than the target, move the third pointer to the right
                    else if (sum < target) {
                        k++;
                    } 
                    // If the sum is greater than the target, move the fourth pointer to the left
                    else {
                        l--;
                    }
                }
            }
        }
        // Return the resulting vector of quadruplets
        return temp;
    }
};