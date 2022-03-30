void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[i] = true;

    for (auto ngbr : adj[i])
        if (vis[ngbr] == false)
            dfs(ngbr, adj, vis);
}

int Solution::motherVertex(int V, vector<vector<int> > &B) {
    vector<vector<int>> adj(V + 1);

    for (vector<int> e : B)
        adj[e[0]].push_back(e[1]);

    int ans;
    vector<bool> vis(V + 1, false);

    for (int i = 1; i <= V; i++)
        if (vis[i] == false) {
            dfs(i, adj, vis);
            ans = i;
        }

    fill(vis.begin(), vis.end(), false);

    dfs(ans, adj, vis);

    for (int i = 1; i <= V; i++)
        if (vis[i] == false) return 0;

    return 1;
}


// https://www.interviewbit.com/problems/mother-vertex/