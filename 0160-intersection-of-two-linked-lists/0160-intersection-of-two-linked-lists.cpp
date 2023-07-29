class Solution {
public:
    int length(ListNode* head){
        int len=0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        bool larger=0;
        if(l1>l2){
            larger = 1;
        }
        int diff = abs(l1-l2);
        if(larger){
            for(int i=0;i<diff;i++)headA = headA->next;
        }
        else{
            for(int i=0;i<diff;i++)headB = headB->next;
        }
        while(headA!=headB){
            headA= headA->next;
            headB = headB->next;
        }
        return headA;
    }
};