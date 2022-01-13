int Solution::solve(vector<int> &A, int B)
{
    int j = -1;
    int zeroes = 0;
    int maxLen = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            zeroes++;

        while (zeroes > B)
        {
            j++;
            if (A[j] == 0)
                zeroes--;
        }

        int len = i - j;
        maxLen = max(maxLen, len);
    }

    return maxLen;
}


// https://www.interviewbit.com/problems/maximum-ones-after-modification/