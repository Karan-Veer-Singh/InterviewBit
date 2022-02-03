/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root)
{
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    unordered_map<int, vector<int>> m;
    queue<pair<TreeNode*, int>> q;
    int dist = 0;

    q.push({root, dist});

    TreeNode *node;
    int mn = INT_MAX;
    int mx = INT_MIN;

    while (!q.empty())
    {
        node = q.front().first;
        dist = q.front().second;

        q.pop();

        m[dist].push_back(node->val);

        if (node->left)
            q.push({node->left, dist - 1});

        if (node->right)
            q.push({node->right, dist + 1});

        mn = min(mn, dist);
        mx = max(mx, dist);
    }

    for (int i = mn; i <= mx; i++)
        ans.push_back(m[i]);

    return ans;
}


// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/