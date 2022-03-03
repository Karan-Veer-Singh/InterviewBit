int Solution::solve(string A)
{
    int len = 0, num = 0, lc = 0, uc = 0, sc = 0;

    for (int i = 0; A[i]; i++)
    {
        char ch = A[i];

        if (ch >= '0' && ch <= '9')
            num++;

        else if (ch >= 'a' && ch <= 'z')
            lc++;

        else if (ch >= 'A' && ch <= 'Z')
            uc++;

        else if ( (ch >= 32 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126) )
            sc++;

        len++;
    }

    if (len < 8 || len > 15 || num == 0 || lc == 0 || uc == 0 || sc == 0)
        return false;

    return true;

}


// https://www.interviewbit.com/problems/valid-password/