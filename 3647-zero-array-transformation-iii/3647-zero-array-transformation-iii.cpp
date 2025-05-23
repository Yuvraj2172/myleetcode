class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int usedQueries=0;

        sort(begin(queries),end(queries));

        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<>>minHeap;

        int j=0;
        for(int i=0;i<n;i++){
            while(j<queries.size() && queries[j][0]==i){
                maxHeap.push(queries[j][1]);
                j++;
            }

            nums[i]-=minHeap.size();

            while(nums[i]>0 && !maxHeap.empty() && maxHeap.top()>=i){
                int top=maxHeap.top(); maxHeap.pop();
                minHeap.push(top);
                usedQueries++;
                nums[i]--;
            }
            
            if(nums[i]>0) return -1;

            while(!minHeap.empty() && minHeap.top()<=i){
                minHeap.pop();
            }
        }
        return queries.size()-usedQueries;
    }
};