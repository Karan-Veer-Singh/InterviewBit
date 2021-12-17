int Solution::solve(vector<int> &A)
{
    unordered_map<int, int> m;
    int n = A.size();
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += A[i] == 0 ? -1 : 1;

        if (sum == 1)
            maxLen = i + 1;

        else if (m.find(sum) == m.end())
            m[sum] = i;

        if (m.find(sum - 1) != m.end())
        {
            int len = i - m[sum - 1];
            maxLen = max(len, maxLen);
        }
    }

    return maxLen;
}


// https://www.interviewbit.com/problems/longest-subarray-length/