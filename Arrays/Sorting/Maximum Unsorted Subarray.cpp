vector<int> Solution::subUnsort(vector<int> &A)
{
    int left = INT_MAX;
    int right = INT_MIN;
    int n = A.size();

    for (int i = 1; i < n; i++)
        if (A[i] < A[i - 1])
            left = min(left, A[i]);

    for (int i = n - 2; i >= 0; i--)
        if (A[i] > A[i + 1])
            right = max(right, A[i]);

    if (left == INT_MAX && right == INT_MIN)
        return { -1};

    int start = 0, end = n - 1;

    for (; start < n; start++)
        if (A[start] > left)
            break;

    for (; end >= 0; end--)
        if (A[end] < right)
            break;

    vector<int> ans;
    ans.push_back(start);
    ans.push_back(end);

    return ans;
}


// https://www.interviewbit.com/problems/maximum-unsorted-subarray/