int Solution::solve(vector<int> &A, int B)
{
    sort(A.begin(), A.end());

    int n = A.size();
    int i = 0;
    int j = 1;

    while (i < n && j < n)
    {
        int diff = abs(A[j] - A[i]);
        int target = abs(B);

        if (i != j && diff == target)
            return 1;

        if (diff < target)
            j++;

        else
            i++;
    }

    return 0;
}


// https://www.interviewbit.com/problems/pair-with-given-difference/