class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
        ListNode* temp = head;
        int len=1;
        while(temp->next){
            len++;
            temp = temp->next;
        }
        temp->next = head;
        k = k%len;
        k = len - k;
        // temp = head;
        while(k-- > 0){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};