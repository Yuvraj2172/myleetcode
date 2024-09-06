class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto it : s)cout<<it<<" ";
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;

        while(head){
            if(s.count(head->val) == 0){
                temp -> next  = new ListNode(head->val);
                temp = temp->next;
            }
            head = head->next;
        }

        return newHead->next;
    }
};