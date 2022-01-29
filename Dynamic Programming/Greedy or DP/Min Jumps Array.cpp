int Solution::jump(vector<int> &A)
{
    int jumps = 0;
    int maxReach = 0;
    int currEnd = 0;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        if (n <= 1)
            return 0;

        if (A[0] == 0)
            return -1;

        maxReach = max(maxReach, i + A[i]);

        if (maxReach >= n - 1)
            return 1 + jumps;

        if (i == maxReach)
            return -1;

        if (i == currEnd) {
            jumps++;
            currEnd = maxReach;
        }
    }
}


// https://www.interviewbit.com/problems/min-jumps-array/