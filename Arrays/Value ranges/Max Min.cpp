int Solution::solve(vector<int> &A)
{
    int maxElement;
    int minElement;
    int n = A.size();
    int i;

    if (n % 2 == 0)
    {
        maxElement = max(A[0], A[1]);
        minElement = min(A[0], A[1]);
        i = 2;
    }
    else
    {
        maxElement = A[0];
        minElement = A[0];
        i = 1;
    }

    while (i < n - 1)
    {
        if (A[i] > A[i + 1])
        {
            maxElement = max(A[i], maxElement);
            minElement = min(A[i + 1], minElement);
        }
        else
        {
            maxElement = max(A[i + 1], maxElement);
            minElement = min(A[i], minElement);
        }

        i += 2;
    }

    return (minElement + maxElement);
}

/* Number of comparisons

       If n is odd:    3*(n-1)/2
       If n is even:   1 Initial comparison for initializing min and max,
                       and 3(n-2)/2 comparisons for rest of the elements
                       =  1 + 3*(n-2)/2 = 3n/2 -2       */


// https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/