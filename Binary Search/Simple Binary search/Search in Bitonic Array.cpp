int peak(vector<int> &A, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
            return mid;
        else if (A[mid + 1] > A[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binarySearch(vector<int> &A, int low, int high, int b)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (A[mid] == b)
            return mid;
        else if (A[mid] < b)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int revBinarySearch(vector<int> &A, int low, int high, int b)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (A[mid] == b)
            return mid;
        else if (A[mid] < b)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    int p = peak(A, 0, n - 1);
    int ans = 0;

    if (B <= A[p])
        ans = binarySearch(A, 0, p, B);

    if (ans != -1)
        return ans;
    else
        return revBinarySearch(A, p + 1, n - 1, B);
}


// https://www.interviewbit.com/problems/search-in-bitonic-array/