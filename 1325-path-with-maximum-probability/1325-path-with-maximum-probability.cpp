class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0 ;i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v,prob);
            graph[v].emplace_back(u,prob);
        }

        vector<double> maxProb(n,0.0);
        maxProb[start] = 1.0;

        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& neighbor : graph[node]){
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;

                double newProb = maxProb[node] * edgeProb;
                if(newProb > maxProb[nextNode]){
                    maxProb[nextNode] = newProb;
                    q.push(nextNode);
                }
            }
        }

        return maxProb[end];

    }
};