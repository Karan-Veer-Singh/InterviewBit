vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    vector<int> ans;

    int m1[100001] = {0};
    int m2[100001] = {0};
    int m3[100001] = {0};

    for (int i : A)  m1[i]++;
    for (int i : B)  m2[i]++;
    for (int i : C)  m3[i]++;

    for (int i = 1; i <= 100000; i++)
        if ( (m1[i] > 0 && m2[i] > 0) || (m2[i] > 0 && m3[i] > 0) || (m3[i] > 0 && m1[i] > 0) )
            ans.push_back(i);

    return ans;
}


// https://www.interviewbit.com/problems/two-out-of-three/