class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* , int> mp;
        while(head){
            if(mp.find(head)!= mp.end())return head;
            mp[head]++;
            head = head->next;
        }
        return NULL;
    }
};