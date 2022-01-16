vector<int> Solution::nextPermutation(vector<int> &A)
{
    int n = A.size();

    if (n == 1)
        return A;

    int i, j;
    for (i = n - 2; i >= 0; i--)
        if (A[i] < A[i + 1])
            break;

    if (i < 0)
    {
        reverse(A.begin(), A.end());
        return A;
    }

    for (j = n - 1; j > i; j--)
        if (A[j] > A[i])
            break;

    swap(A[i], A[j]);
    reverse(A.begin() + i + 1, A.end());
    return A;
}


// https://www.interviewbit.com/problems/next-permutation/