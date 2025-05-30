class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n = len(edges)
        inf = 1 << 32
        dis1 = [inf] * n
        dis2 = [inf] * n

        def dfs(start, dist):
            d, node = 0,start
            while node!= -1 and dist[node] == inf:
                dist[node] = d
                d +=1
                node = edges[node]
        dfs(node1, dis1)
        dfs(node2,dis2)

        ans, res = inf, -1 
        for i in range(n):
            maxdis = max(dis1[i], dis2[i])
            if ans > maxdis:
                ans = maxdis
                res = i
        return res