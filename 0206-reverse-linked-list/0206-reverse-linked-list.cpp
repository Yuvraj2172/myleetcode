class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head== NULL || head->next == NULL )return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while(curr!=NULL){
            ListNode* temp = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head->next = NULL;
        return prev;
    }
};