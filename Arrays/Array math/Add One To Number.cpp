vector<int> Solution::plusOne(vector<int> &A)
{
    int n = A.size();
    vector<int> ans;

    if (n == 0 || (n == 1 && A[0] == 0) )
        return {1};

    for (int p = n - 1; p >= 0; p--)
        if (A[p] == 9)
        {
            A[p] = 0;
            if (p == 0)
            {
                A.insert(A.begin(), 1);
                return A;
            }
        }
        else
        {
            A[p] += 1;
            break;
        }

    int i = 0;
    while (i < n)
        if (A[i] == 0)
            i++;
        else
            break;

    for (int k = i; k < n; k++)
        ans.push_back(A[k]);

    return ans;
}


// https://www.interviewbit.com/problems/add-one-to-number/