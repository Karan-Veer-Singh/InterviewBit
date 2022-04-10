vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    int left = 0, right = 0;
    while (right < n)
        if (A[right] != 0)   swap(A[left++], A[right++]);
        else    right++;

    return A;
}

// https://www.interviewbit.com/problems/chips-factory/