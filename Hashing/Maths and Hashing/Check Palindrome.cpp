int Solution::solve(string A)
{
    map<int, int> m;
    int count = 0;

    for (char ch : A)
        m[ch]++;

    for (auto p : m)
    {
        int i = p.second;
        if (i % 2 != 0)
            count++;
    }

    if (count > 1)
        return 0;
    else
        return 1;
}


// https://www.interviewbit.com/problems/check-palindrome/