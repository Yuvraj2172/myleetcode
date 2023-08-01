class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
        int len = 1;
        ListNode* temp = head;
        while(temp->next){
            temp= temp->next;
            len++;
        }
        temp->next = head;
        k = k%len;
         k = len - k;
        while(k-- > 0){
            temp = temp->next;
        }
        head = temp->next;
        temp ->next = NULL;
        return head;
    }
};