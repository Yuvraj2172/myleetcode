class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int j = 0, i = 0;
        int res = 0;
        for (i = 0; i < fruits.size(); i++) {
            basket[fruits[i]] = basket.count(fruits[i]) ? basket[fruits[i]] + 1 : 1;
            while (basket.size() > 2) {
                basket[fruits[j]]--;
                if (basket[fruits[j]] == 0) {
                    basket.erase(fruits[j]);
                }
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};