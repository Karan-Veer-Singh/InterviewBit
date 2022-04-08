int Solution::solve(vector<int> &A, int B) {
    int count = 0, i = 0, n = A.size();

    while (i < n) {
        int right = min(i + B - 1, n - 1);
        int left = max(i - B + 1, 0);
        bool bulbFound = false;

        while (right >= left) {
            if (A[right] == 1) {
                bulbFound = true;
                break;
            }
            right--;
        }

        if (bulbFound == false)  return -1;

        count++;
        i = right + B;
    }
    return count;
}


// https://www.interviewbit.com/problems/minimum-lights-to-activate/