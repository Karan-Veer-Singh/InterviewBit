int Solution::solve(vector<int> &A)
{
    unordered_set<int> s;
    int n = A.size();
    int ans = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        int element = A[i];
        if (s.find(element) != s.end())
            ans = element;
        else
            s.insert(element);
    }

    return ans;
}


// https://www.interviewbit.com/problems/first-repeating-element/