string Solution::solve(string A, int B)
{
    string ans;
    int i = 0;
    int n = A.size();

    while (i < n)
    {
        string temp = "";
        temp.push_back(A[i]);
        int j = i + 1;
        int count = 1;

        while (j < n && A[i] == A[j])
        {
            temp += A[j];
            count++;
            j++;
            i++;
        }

        i++;

        if (count != B)
            ans += temp;
    }

    return ans;
}


// https://www.interviewbit.com/problems/remove-consecutive-characters/