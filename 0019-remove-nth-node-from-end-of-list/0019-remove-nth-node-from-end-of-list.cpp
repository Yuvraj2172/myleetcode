class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* fast = dummy ;
        while(n--){
            fast = fast->next;
        }
        ListNode* slow = dummy;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};