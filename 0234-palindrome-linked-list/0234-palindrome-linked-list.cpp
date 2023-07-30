class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        for(int i=0;i<v.size()/2; i++){
            if(v[i]!= v[v.size() -1 -i])return 0;
        }
        return 1;
    }
};