class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        int[][] direction = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        double[][] pre = new double[n][n];
        double[][] cur = new double[n][n];
        pre[row][column] = 1;
        for(int m = 1; m <= k; m++){
            for(double[] fresh : cur){
                Arrays.fill(fresh, 0.0);
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(pre[i][j] == 0.0) continue;
                    for(int[] dir : direction){
                        int curR = i + dir[0];
                        int curC = j + dir[1];
                        if(curR >= 0 && curR < n && curC >= 0 && curC < n){
                            cur[curR][curC] += pre[i][j] / 8.0;
                        }
                    }
                }
            }
            double[][] tmp = pre;
            pre = cur;
            cur = tmp;
        }
        double ans = 0.0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans += pre[i][j];
            }
        }
        return ans;
    }}