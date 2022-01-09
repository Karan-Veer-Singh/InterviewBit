int Solution::repeatedNumber(const vector<int> &A)
{
    int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
    int len = A.size();

    for (int i = 0; i < len; i++)
    {
        int ele = A[i];

        if (ele == num1)
            c1++;
        else if (ele == num2)
            c2++;
        else if (c1 == 0)
        {
            num1 = ele;
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = ele;
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    c1 = 0;
    c2 = 0;

    for (int i = 0; i < len; i++)
    {
        if (A[i] == num1)
            c1++;
        else if (A[i] == num2)
            c2++;
    }

    int ans = -1;

    if (c1 > len / 3)
        ans = num1;
    else if (c2 > len / 3)
        ans = num2;

    return ans;
}


// https://www.interviewbit.com/problems/n3-repeat-number/