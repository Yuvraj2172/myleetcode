class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int parts) {
        int n =0;
        ListNode* t2 = head;
        while(t2){
            t2 = t2->next;
            n++; 
        }
        int width = n / parts, rem = n%parts;
        vector<ListNode*> ans;
        ListNode* cur = head;
        for(int i=0; i< parts; i++){
            ListNode* ithpart = new ListNode(0);
            ListNode* temp = ithpart;
            // int add = (rem !=  0) ? 1 : 0;
            for(int j = 0; j< width + (i< rem ? 1 : 0) ; j++){
                ListNode* newNode = new ListNode(cur->val);
                temp -> next = newNode;
                temp = temp->next;
                if(cur)cur = cur->next;
            }
            // rem--;
            ans.push_back(ithpart->next);
        }
        return ans;
    }
};