int Solution::solve(vector<int> &A, int B)
{
    priority_queue<int> pq(A.begin(), A.end());
    int ans = 0;

    while (B--)
    {
        int temp = pq.top();
        pq.pop();

        ans += temp;
        pq.push(temp - 1);
    }

    return ans;
}


// https://www.interviewbit.com/problems/profit-maximisation/