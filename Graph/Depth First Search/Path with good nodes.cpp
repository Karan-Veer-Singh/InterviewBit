void dfs(int node, vector<bool> &vis, vector<int> adj[], vector<int> &A, int &maxCount, int count, int &path)
{
    vis[node] = true;

    if (A[node - 1] == 1)      count++;

    if (count > maxCount)    return;

    int flag = 0;

    for (auto ngbr : adj[node])
    {
        if (vis[ngbr] == 0)
        {
            flag = 1;
            dfs(ngbr, vis, adj, A, maxCount, count, path);
        }
    }

    if (flag == 0)
        path++;
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C)
{
    int n = A.size();
    vector<int> adj[n + 1];

    for (int i = 0; i < B.size(); i++)
    {
        int u = B[i][0];
        int v = B[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int path = 0;
    vector<bool> vis(n + 1, false);

    dfs(1, vis, adj, A, C, 0, path);

    return path;
}


// https://www.interviewbit.com/problems/path-with-good-nodes/