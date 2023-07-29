class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        while(1){
            if(d1 == d2)return d1;
            d1= d1==NULL ? headB : d1->next;
            d2 =d2==NULL ? headA : d2->next;
        }
        return NULL;
    }
};