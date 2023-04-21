class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next; 
            fast = fast ->next ->next;
        }
        ListNode* second = slow->next ;
        ListNode* prev = slow->next = NULL;
        while( second!=NULL ){
            ListNode* temp = second ->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        
        second = prev;
        ListNode* first = head;
        while(second!=NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2= second->next;
            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }
        
    }
    
};