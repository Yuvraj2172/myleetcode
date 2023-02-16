class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        int sum =0, carry =0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            sum = carry;
            if(l1!=NULL){
                sum += l1->val;
                l1 = l1->next;
            } 
            if(l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(sum%10);
            carry = sum/10;
            temp = temp->next;
        }
        return res->next;
    }
};