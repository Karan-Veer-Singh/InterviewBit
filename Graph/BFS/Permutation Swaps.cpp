int findSet(int i, vector<int> &parent) {
    if (parent[i] == -1) return i;
    return parent[i] = findSet(parent[i], parent);
}

void unionSet(int x, int y, vector<int> &parent, vector<int> &rank) {
    int s1 = findSet(x, parent);
    int s2 = findSet(y, parent);

    if (s1 != s2) {
        if (rank[s1] < rank[s2]) {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
        else {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();
    vector<int> parent(n + 1, -1);
    vector<int> rank(n + 1, 1);

    for (vector<int> v : C) {
        int x = A[v[0] - 1];
        int y = A[v[1] - 1];

        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if (s1 != s2)    unionSet(s1, s2, parent, rank);
    }

    for (int i = 0; i < n; i++)
        if (A[i] != B[i] && findSet(A[i], parent) != findSet(B[i], parent))  return 0;

    return 1;
}

// https://www.interviewbit.com/problems/permutation-swaps/