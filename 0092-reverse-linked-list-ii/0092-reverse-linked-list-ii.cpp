class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right -  left == 0)return head;
        vector<int> temp;
        ListNode* t = head;
        while(t){
            temp.push_back(t->val);
            t = t->next;
        }
        left-=1; right-=1;
        while(left < right)swap(temp[left++], temp[right--]);
        for(auto it : temp)cout<<it<<" ";
        ListNode* ans = new ListNode(0);
        t = ans;
        for(auto it : temp){
            t->next = new ListNode(it);
            t = t->next;
        }
        return ans->next;
    }
};