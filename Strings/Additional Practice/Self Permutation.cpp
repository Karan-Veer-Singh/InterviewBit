int Solution::permuteStrings(string A, string B)
{
    if (A.length() != B.length())
        return 0;

    map<char, int> m;
    for (char ch : A)
        m[ch]++;

    for (char ch : B)
        m[ch]--;

    for (auto p : m)
        if (p.second != 0)
            return 0;

    return 1;
}


// https://www.interviewbit.com/problems/self-permutation/