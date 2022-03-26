int Solution::maxProfit(const vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                int profit = 0;
                if (buy) {
                    int take = -prices[i] + after[0][cap];
                    int notTake = after[1][cap];
                    profit = max(take, notTake);
                }
                else {
                    int sell = prices[i] + after[1][cap - 1];
                    int notSell = after[0][cap];
                    profit = max(sell, notSell);
                }

                curr[buy][cap] = profit;
            }
        }
        after = curr;
    }

    return after[1][2];
}

// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/