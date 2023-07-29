class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        unordered_map<ListNode*, int> mp;
        while(slow){
            if(mp.find(slow)!= mp.end())return 1;
            mp[slow]++;
            slow= slow->next;
        }
        return 0;
        
    }
};