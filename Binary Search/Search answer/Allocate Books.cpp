bool isPossible(vector<int> &A, int pages, int students)
{
    int studentCount = 0;
    int pagesAllocated = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (pagesAllocated + A[i] > pages)
        {
            studentCount++;
            pagesAllocated = A[i];
        }
        else
        {
            pagesAllocated += A[i];
        }
    }

    return studentCount < students ? true : false;
}

int Solution::books(vector<int> &A, int B)
{
    if (B > A.size())    return -1;

    int low = A[0];
    int high = 0;

    for (int i = 0; i < A.size(); i++)
    {
        high += A[i];
        low = max(low, A[i]);
    }

    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isPossible(A, mid, B))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}


// https://www.interviewbit.com/problems/allocate-books/