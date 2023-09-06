class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int parts) {
        int n =0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        int width = n / parts;
        int rem = n % parts;
        vector<ListNode*> ans;
        ListNode* cur = head;
        for(int i=0; i<parts; i++){
            ListNode* ithPart = new ListNode(0);
            ListNode* temp = ithPart;
            int limit = width;
            if(rem!=0){
                limit = width +1;
                rem--;
            }
            for(int j=0; j < limit; j++){
                temp->next = new ListNode(cur->val);
                temp = temp->next;
                if(cur)cur = cur->next;
            }
            ans.push_back(ithPart->next);
        }
        return ans;
    }
};