int Solution::diffPossible(const vector<int> &A, int k)
{
    unordered_set<int> s;

    for (int i = 0; i < A.size(); i++)
    {
        int a = A[i] - k;
        int b = A[i] + k;

        if (s.find(a) != s.end() || s.find(b) != s.end())
            return 1;

        s.insert(A[i]);
    }

    return 0;
}


// https://www.interviewbit.com/problems/diffk-ii/