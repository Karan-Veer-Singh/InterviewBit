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


// https://www.interviewbit.com/problems/cycle-in-undirected-graph/