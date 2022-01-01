vector<int> Solution::searchRange(const vector<int> &A, int B)
{
    int first = -1;
    int second = -1;

    int start = 0;
    int end = A.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (A[mid] == B)
        {
            first = mid;
            end = mid - 1;
        }
        else if (B < A[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    start = 0;
    end = A.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (A[mid] == B)
        {
            second = mid;
            start = mid + 1;;
        }
        else if (B < A[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return {first, second};
}


// https://www.interviewbit.com/problems/search-for-a-range/