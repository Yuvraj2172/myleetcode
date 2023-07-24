class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int> , greater<int>> pq;
        int n = lists.size();
        for(int i=0;i<n;i++){
            ListNode* temp = lists[i];
            while(temp!=NULL){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        while(!pq.empty()){
            int t = pq.top();
            pq.pop();
            ListNode* newNode = new ListNode(t);
            temp->next = newNode ;
            temp = temp->next;
        }
        return ans->next;
    }
};