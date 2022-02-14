int Solution::solve(int V, vector<vector<int> > &B)
{
    vector<pair<int, int>> adj[V + 1];
    for (vector<int> x : B)
    {
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }

    vector<int> weight(V + 1, INT_MAX);
    vector<bool> mstSet(V + 1, false);

    weight[1] = 0;

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, 1});

    int cost = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int c = pq.top().first;
        pq.pop();

        if (mstSet[node] == true)
            continue;

        cost += c;
        mstSet[node] = true;

        for (auto it : adj[node])
        {
            int ngbr = it.first;
            int w = it.second;

            if (mstSet[ngbr] == false && w < weight[ngbr])
            {
                weight[ngbr] = w;
                pq.push({weight[ngbr], ngbr});
            }
        }
    }

    return cost;
}


// https://www.interviewbit.com/problems/commutable-islands/