int Solution::solve(vector<int> &prices, int k) {
	int n = prices.size();
	k = min(k, n / 2);
	vector<vector<int>> after(2, vector<int>(k + 1, 0));
	vector<vector<int>> curr(2, vector<int>(k + 1, 0));

	for (int i = n - 1; i >= 0; i--) {
		for (int buy = 0; buy <= 1; buy++) {
			for (int cap = 1; cap <= k; cap++) {
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

	return after[1][k];
}

// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stock-atmost-b-times/


