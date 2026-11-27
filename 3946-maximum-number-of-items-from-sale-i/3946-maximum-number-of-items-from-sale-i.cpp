class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> firstVal(n, 1); // Start at 1 to include the purchased item itself
        int minPrice = INT_MAX;

        for (int i = 0; i < n; ++i) {
            minPrice = min(minPrice, items[i][1]);
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    firstVal[i]++;
                }
            }
        }

        // 0/1 Knapsack for the FIRST copy of each item (which grants free copies)
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int val = firstVal[i];

            if (price > budget) continue;

            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + val);
            }
        }

        // Spend any remaining budget on unlimited copies of the cheapest item
        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            ans = max(ans, dp[b] + (budget - b) / minPrice);
        }

        return ans;
    }
};


