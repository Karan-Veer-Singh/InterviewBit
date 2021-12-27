int Solution::solve(vector<vector<int> > &A)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(A.begin(), A.end());

    int rooms = 0;

    for (int i = 0; i < A.size(); i++)
    {
        int start = A[i][0];
        int end = A[i][1];

        if (!pq.empty() && start >= pq.top())
            pq.pop();
        else
            rooms++;

        pq.push(end);
    }

    return rooms;
}

// https://www.interviewbit.com/problems/meeting-rooms/