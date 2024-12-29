class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        self.len_w = len(words[0])
        self.len_t = len(target)
        self.cmap_list = []
        for idx in range(self.len_w):
            cdict = collections.defaultdict(int)
            for w in words:
                cdict[w[idx]] += 1
            self.cmap_list.append(cdict)

        self.target = target
        self.dp = collections.defaultdict(lambda: None)
        ans = 0
        for i in range(self.len_w):
            ans += self.findWays(i, 0)
        return ans % 1000000007
        
    def findWays(self, c_idx, target_idx):
        if self.len_w - c_idx < self.len_t - target_idx:
            return 0

        if self.dp[c_idx, target_idx] is None:
            cnt = self.cmap_list[c_idx][self.target[target_idx]]
            if cnt > 0 and target_idx < self.len_t - 1:
                rest_ways = 0
                for i in range(c_idx + 1, self.len_w + 1):
                    rest_ways += self.findWays(i, target_idx + 1)
                cnt = (cnt * rest_ways) % 1000000007
            self.dp[c_idx, target_idx] = cnt
        return self.dp[c_idx, target_idx]
            