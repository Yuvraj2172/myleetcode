
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v(m, vector<int>(n,0));
        int row = m;
        int col = n;
        int c = head->val;
        int top = 0, bottom = row - 1, left = 0, right = col -1;

        while(left <= right && top <= bottom){
            for(int i = left; i<=right; i++){
                (head ? c = head->val : c = -1);
                v[top][i] = c;
                if(head)head = head->next;
            }
            top++;

            for(int i = top ; i<= bottom ; i++){
                (head ? c = head->val : c = -1);
                v[i][right] = c;
                if(head) head = head->next;
            }
            right--;

            if(top <= bottom){
                for(int i = right; i>=left; i--){
                    (head ? c = head->val : c = -1);
                    v[bottom][i] = c;
                    if(head)head = head->next;
                }
            bottom--;
            }

            if(left <= right){
                for(int i = bottom; i>= top; i--){
                    (head ? c = head->val : c = -1);
                    v[i][left] = c;
                    if(head)head = head->next;
                }
            left++;
            }

        }

        return v;

    }
};