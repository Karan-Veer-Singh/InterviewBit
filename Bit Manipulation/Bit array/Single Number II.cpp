int Solution::singleNumber(const vector<int> &A)
{
    int bits[64] = {0};

    for (int i = 0; i < A.size(); i++)
    {
        int x = A[i];
        int j = 0;

        while (x > 0)
        {
            int lastBit = (x & 1);
            bits[j] += lastBit;
            j++;
            x = x >> 1;
        }
    }

    int p = 1;
    int ans = 0;

    for (int i = 0; i < 64; i++)
    {
        bits[i] %= 3;
        ans += (bits[i] * p);
        p = p << 1;
    }

    return ans;
}


// https://www.interviewbit.com/problems/single-number-ii/