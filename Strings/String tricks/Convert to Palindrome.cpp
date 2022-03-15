bool isPalindrome(string &s, int i, int j)
{
    while (i < j)
        if (s[i] == s[j])
            i++, j--;
        else
            return false;

    return true;
}

int Solution::solve(string s)
{
    int i = 0, j = s.length() - 1;

    while (i < j)
        if (s[i] == s[j])
            i++, j--;
        else
            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);

    return true;
}


// https://www.interviewbit.com/problems/convert-to-palindrome/