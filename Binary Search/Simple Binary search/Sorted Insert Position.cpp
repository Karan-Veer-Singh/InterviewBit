int Solution::searchInsert(vector<int> &A, int B)
{
    int start = 0;
    int end = A.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (A[mid] == B)
            return mid;
        if (B < A[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return start;
}


// https://www.interviewbit.com/problems/sorted-insert-position/