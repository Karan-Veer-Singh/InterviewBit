vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    int m = A.size(),  n = B.size();
    int k = max(m, n) - 1;
    vector<int> ans;
    int i = m - 1, j = n - 1, carry = 0;

    while (k >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0)  sum += A[i];
        if (j >= 0)  sum += B[j];
        ans.push_back(sum % 10);
        carry = sum / 10;
        i--; j--; k--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// https://www.interviewbit.com/problems/array-sum/