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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        int n = lists.size();
        for(int i=0;i<n ;i++){
            ListNode* temp = lists[i];
            while(temp!=nullptr){
                v.push_back(temp->val);
                temp = temp->next;
            }
            
        }
        // for(auto it : v)cout<< it<<" ";
        sort(v.begin(), v.end());
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        for(auto it : v){
            ListNode* newNode = new ListNode(it);
            temp->next = newNode;
            temp = newNode;
        }
        return res->next;
    }
};