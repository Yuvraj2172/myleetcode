#define pip pair<int, pair<int, int>> 

class Solution {
    bool isvalid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
public:
    int trapRainWater(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        if (n < 3 || m < 3) return 0;

        priority_queue<pip, vector<pip>, greater<pip>> mh;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    mh.push(make_pair(arr[i][j], make_pair(i, j)));
                    vis[i][j] = true;
                }
            }
        }

        int level = 0;
        int ans = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!mh.empty()) {
            pip curr = mh.top();
            mh.pop();
            int height = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            level = max(level, height);

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                if (isvalid(nx, ny, n, m) && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    mh.push(make_pair(arr[nx][ny], make_pair(nx, ny)));
                    if (arr[nx][ny] < level) {
                        ans += level - arr[nx][ny];
                    }
                }
            }
        }
        return ans;
    }
};