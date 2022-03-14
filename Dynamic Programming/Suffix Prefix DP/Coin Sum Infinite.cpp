int Solution::coinchange2(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    for (int i = 0; i <= amount; i++)
        prev[i] = (i % coins[0] == 0);

    for (int i = 1; i < n; i++)
    {
        for (int tar = 0; tar <= amount; tar++)
        {
            int notTake = prev[tar];
            int take = 0;
            if (coins[i] <= tar)  take = curr[tar - coins[i]];

            curr[tar] = (take + notTake) % 1000007;
        }

        prev = curr;
    }

    return prev[amount];
}

// https://www.interviewbit.com/problems/coin-sum-infinite/