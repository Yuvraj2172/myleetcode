class Solution {
public:
    int length(ListNode* head){
        int len=0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return head;
        int len = length(head);
        if(len < k)return head;
        int c=0;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        while(c<k && curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            c++;
        }
        if(next)head->next = reverseKGroup(next,k);
        return prev;
    }
};