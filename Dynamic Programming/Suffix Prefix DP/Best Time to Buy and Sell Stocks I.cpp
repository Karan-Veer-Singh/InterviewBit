int Solution::maxProfit(const vector<int> &A) {
	int minPrice = INT_MAX;
	int maxProfit = 0;

	for (int i = 0; i < A.size(); i++) {
		minPrice = min(minPrice, A[i]);
		int cost = A[i] - minPrice;
		maxProfit = max(maxProfit, cost);
	}

	return maxProfit;
}


// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/