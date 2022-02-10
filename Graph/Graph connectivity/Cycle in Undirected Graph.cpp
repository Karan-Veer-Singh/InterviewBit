// DFS

bool detectCycle(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;

    for (auto ngbr : adj[node])
    {
        if (vis[ngbr] == 0)
        {
            if (detectCycle(ngbr, node, vis, adj))
                return true;
        }
        else if (ngbr != parent)
        {
            return true;
        }
    }

    return false;
}

int Solution::solve(int V, vector<vector<int> > &B)
{
    vector<int> adj[V + 1];

    for (int i = 0; i < B.size(); i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    vector<int> vis(V + 1, 0);

    for (int i = 1; i <= V; i++)
        if (vis[i] == 0)
            if (detectCycle(i, -1, vis, adj))
                return true;

    return false;
}


// BFS

bool detectCycle(int src, vector<int> &vis, vector<int> adj[])
{
    vis[src] = 1;

    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto ngbr : adj[node])
        {
            if (vis[ngbr] == 0)
            {
                vis[ngbr] = 1;
                q.push({ngbr, node});
            }
            else
            {
                if (ngbr != parent)
                    return true;
            }
        }
    }

    return false;
}

int Solution::solve(int V, vector<vector<int> > &B)
{
    vector<int> adj[V + 1];

    for (int i = 0; i < B.size(); i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    vector<int> vis(V + 1, 0);

    for (int i = 1; i <= V; i++)
        if (vis[i] == 0)
            if (detectCycle(i, vis, adj))
                return true;

    return false;
}


// https://www.interviewbit.com/problems/cycle-in-undirected-graph/