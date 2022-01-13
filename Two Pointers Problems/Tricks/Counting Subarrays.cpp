int Solution::solve(vector<int> &A, int B)
{
    int j = 0;
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];

        while (sum >= B)
        {
            sum -= A[j];
            j++;
        }

        ans += (i - j + 1);
    }

    return ans;
}


// https://www.interviewbit.com/problems/counting-subarrays/