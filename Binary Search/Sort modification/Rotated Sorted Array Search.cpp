int Solution::search(const vector<int> &A, int B)
{
    int start = 0;
    int end = A.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (A[mid] == B)
            return mid;

        if (A[start] <= A[mid])
        {
            if (B >= A[start] && B <= A[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if (B >= A[mid] && B <= A[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

// https://www.interviewbit.com/problems/rotated-sorted-array-search/