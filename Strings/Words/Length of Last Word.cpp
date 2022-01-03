int Solution::lengthOfLastWord(const string A)
{
    int n = A.length();
    int count = 0;

    while (n > 0)
    {
        if (A[--n] != ' ')
            count++;
        else if (count > 0)
            return count;
    }

    return count;
}


// https://www.interviewbit.com/problems/length-of-last-word/