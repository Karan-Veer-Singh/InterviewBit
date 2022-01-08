int Solution::isPalindrome(int A)
{
    if (A < 0)
        return false;

    int x = A;
    long long int num = 0;

    while (x > 0)
    {
        int d = x % 10;
        num = num * 10 + d;
        x /= 10;
    }

    return (num == A);
}


// https://www.interviewbit.com/problems/palindrome-integer/