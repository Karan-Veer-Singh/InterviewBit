vector<int> Solution::flip(string A) {
    vector<int> ans;
    int curr = 0, maxa = 0, l = 0, lmax = -1, rmax = -1;
    for (int i = 0; i < A.size(); i++) {
        (A[i] == '0') ? curr++ : curr--;
        if (curr > maxa) {
            maxa = curr;
            lmax = l;
            rmax = i;
        }
        if (curr < 0) {
            curr = 0;
            l = i + 1;
        }
    }

    if (lmax == -1 || rmax == -1)    return ans;
    ans.push_back(lmax + 1);
    ans.push_back(rmax + 1);
    return ans;
}

// https://www.interviewbit.com/problems/flip/