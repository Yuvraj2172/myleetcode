class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(head){
            next = head->next;
            head->next = pre;
            pre = head ;
            head = next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return 1;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow){
            if(head->val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow ->next;
        }
        return 1;
        
    }
};