/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        vector<int> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        vector<int> t;
        for(int i=0; i<v.size()-1; i++){
            int curr = v[i];
            int next = v[i+1];
            int g= __gcd(curr, next);
            t.push_back(curr);
            t.push_back(g);
            // t.push_back(next);
        }
        t.push_back(v[v.size()-1]);
        ListNode* ans = new ListNode(0);
        temp = ans;
        for(auto it : t){
            temp -> next = new ListNode(it);
            temp = temp->next;
        }
        return ans->next;
    }
};