vector<int> Solution::lszero(vector<int> &A)
{
    int n = A.size();
    int preSum = 0;
    int maxLen = 0;

    vector<int> ans;
    unordered_map<int, int> m;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += A[i];

        if (preSum == 0)
        {
            int len = i + 1;
            if (len > maxLen)
            {
                maxLen = len;
                start = 0;
            }
        }
        else if (m.find(preSum) != m.end())
        {
            int len = i - m[preSum];
            if (len > maxLen)
            {
                maxLen = len;
                start = m[preSum] + 1;
            }
        }
        else
            m[preSum] = i;
    }

    for (int i = start; i < (start + maxLen); i++)
        ans.push_back(A[i]);

    return ans ;
}


// https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/