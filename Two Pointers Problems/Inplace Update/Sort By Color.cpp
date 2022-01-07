void Solution::sortColors(vector<int> &A)
{
    int n = A.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (A[mid] == 0)
        {
            swap(A[low], A[mid]);
            low++;
            mid++;
        }
        else if (A[mid] == 2)
        {
            swap(A[mid], A[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
}

// Time Complexity: O(N).
// Dutch National Flag Algorithm.


// https://www.interviewbit.com/problems/sort-by-color/