int Solution::nchoc(int A, vector<int> &B)
{
    priority_queue<int> pq(B.begin(), B.end());
    long long int ans = 0;

    while (A--)
    {
        int temp = pq.top();
        pq.pop();

        ans = (ans + temp) % 1000000007;

        pq.push(temp / 2);
    }

    return ans;
}


// https://www.interviewbit.com/problems/magician-and-chocolates/