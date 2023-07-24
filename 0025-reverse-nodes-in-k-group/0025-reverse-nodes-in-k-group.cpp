class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)return NULL;
        int len=0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp= temp->next;
            len++;
        }
        if(len<k)return head;
        int c=0;
        ListNode* curr = head; 
        ListNode* prev = NULL;
        ListNode* n = NULL;
        while(curr!=NULL && c<k){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
            c++;
        }
        if(n)head->next = reverseKGroup(n,k);
        return prev;
    }
};