int Solution::solve(vector<int> &A) {
    int count = 1;
    int mx = A[0];

    for (int i = 1; i < A.size(); i++) {
        if (A[i] > mx) {
            count++;
            mx = A[i];
        }
    }
    return count;
}

// https://www.interviewbit.com/problems/greater-than-all/