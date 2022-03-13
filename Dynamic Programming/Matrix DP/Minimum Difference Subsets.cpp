int Solution::solve(vector<int> &A)
{
    int n = A.size();
    int totalSum = 0;

    for (int i : A)   totalSum += i;

    int B = totalSum;

    vector<bool> prev(B + 1, 0), curr(B + 1, 0);

    prev[0] = curr[0] = true;

    if (A[0] <= B)  prev[A[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= B; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (A[i] <= target)
                take = prev[target - A[i]];

            curr[target] = take || notTake;
        }

        prev = curr;
    }

    int mini = 1e9;
    for (int s1 = 0; s1 <= totalSum / 2; s1++)
    {
        if (prev[s1] == true)
        {
            int s2 = totalSum - s1;

            mini = min(mini, abs(s2 - s1));
        }
    }

    return mini;
}


// https://www.interviewbit.com/problems/minimum-difference-subsets/