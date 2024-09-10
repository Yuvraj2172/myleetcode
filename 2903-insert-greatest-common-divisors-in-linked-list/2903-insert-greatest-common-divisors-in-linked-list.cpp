class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        
        if(!head || !head->next)return head
        ;

        while( curr->next!=NULL){
            ListNode* currentnode = curr;
            ListNode* nextnode = curr->next;

            ListNode* gcdNode = new ListNode(__gcd(currentnode->val,    nextnode->val));

            currentnode -> next = gcdNode;
            gcdNode ->next = nextnode;

            curr = gcdNode->next;
        }

        return head;
    }
};