vector<int> Solution::maxone(vector<int> &A, int B)
{
    int j = -1;
    int count = 0;
    int maxLen = 0;
    int left = 0;
    int right = 0;

    vector<int> ans;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            count++;

        while (count > B)
        {
            j++;
            if (A[j] == 0)
                count--;
        }

        int len = i - j;
        if (len > maxLen)
        {
            maxLen = len;
            left = j;
            right = i;
        }
    }

    for (int i = left + 1; i <= right; i++)
        ans.push_back(i);

    return ans;
}


// https://www.interviewbit.com/problems/max-continuous-series-of-1s/