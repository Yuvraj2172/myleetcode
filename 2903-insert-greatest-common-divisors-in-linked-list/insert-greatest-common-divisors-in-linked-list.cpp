class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* curr = head;
        while(curr->next){
            ListNode* d = new ListNode(__gcd(curr->val, curr->next->val));
            d->next = curr->next;
            curr->next = d;
            curr = d->next;
        }
        return head;
    }
};