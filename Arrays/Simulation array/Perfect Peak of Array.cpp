int Solution::perfectPeak(vector<int> &A)
{
    int n = A.size();
    int leftMax[n];
    int righMin[n];

    leftMax[0] = A[0];
    righMin[n - 1] = A[n - 1];

    for (int i = 1; i < n; i++)
        leftMax[i] = max(A[i], leftMax[i - 1]);

    for (int i = n - 2; i >= 0; i--)
        righMin[i] = min(A[i], righMin[i + 1]);

    for (int i = 1; i <= n - 2; i++)
        if (A[i] > leftMax[i - 1] && A[i] < righMin[i + 1])
            return 1;

    return 0;
}


//https://www.interviewbit.com/problems/perfect-peak-of-array/