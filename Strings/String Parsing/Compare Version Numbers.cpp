int Solution::compareVersion(string v1, string v2)
{
    unsigned long long int m = v1.length();
    unsigned long long int n = v2.length();
    unsigned long long int i = 0, j = 0;
    unsigned long long int val1,  val2;

    while (i < m || j < n)
    {
        val1 = 0, val2 = 0;

        while (i < m && v1[i] != '.')
        {
            val1 = val1 * 10 + (v1[i] - '0');
            i++;
        }

        while (j < n && v2[j] != '.')
        {
            val2 = val2 * 10 + (v2[j] - '0');
            j++;
        }

        if (val1 > val2)
            return 1;

        else if (val1 < val2)
            return -1;

        i++;
        j++;
    }

    return 0;
}


// https://www.interviewbit.com/problems/compare-version-numbers/