class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)return 0;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast->next->next !=NULL && fast->next != NULL){
            if(slow == fast)return 1;
            slow = slow->next;
            fast = fast->next->next;
        }
        return 0;
    }
};