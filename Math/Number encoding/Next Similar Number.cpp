string Solution::solve(string A)
{
    int n = A.length();
    int i, j;

    for (i = n - 2; i >= 0; i--)
        if (A[i] < A[i + 1])
            break;

    if (i < 0)
        return "-1";

    for (j = n - 1; j > i; j--)
        if (A[j] > A[i])
            break;

    swap(A[i], A[j]);

    reverse(A.begin() + i + 1, A.end());

    return A;
}


// https://www.interviewbit.com/problems/next-similar-number/