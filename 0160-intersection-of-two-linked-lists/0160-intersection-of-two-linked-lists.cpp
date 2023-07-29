class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        while(headA){
            mp[headA]++;
            headA = headA->next;
        }
        while(headB){
            if(mp.find(headB)!= mp.end()){
                return headB;
            }
             headB = headB->next;
        }
        return NULL;
    }
};