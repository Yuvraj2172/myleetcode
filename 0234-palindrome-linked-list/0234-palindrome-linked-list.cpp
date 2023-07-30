class Solution {
public:
    //reverses a linked list
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // if(!head || !head->next)return 1;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Middle of the list
         while(fast->next && fast->next->next){ 
            slow = slow->next;
            fast = fast->next ->next;
        }
        
        slow -> next = reverse(slow->next);
        slow = slow->next;
        while(slow){
            if(head->val != slow->val)return 0;
            slow = slow ->next  ; head = head->next;
        }
        return 1;
    }
};