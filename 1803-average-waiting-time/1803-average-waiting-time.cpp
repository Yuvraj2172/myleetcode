class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& arr) {
        int n = arr.size();
        double time_waiting = arr[0][1];
        int finished_prev = arr[0][0] + arr[0][1];

        for(int i = 1; i<n;i++){
            vector<int> temp = arr[i];

            int arrive = temp[0];
            int start_time = max(finished_prev, arrive);

            int end_time = start_time + temp[1];
            finished_prev = end_time;

            time_waiting += (end_time - arrive);

        }
        return time_waiting/n;

    }
};