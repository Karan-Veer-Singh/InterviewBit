/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool getPath(vector<int> &path, TreeNode *root, int k)
{
    if (root == NULL)
        return false;

    path.push_back(root->val);

    if (root->val == k)
        return true;

    if (getPath(path, root->left, k) || getPath(path, root->right, k))
        return true;

    path.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* root, int k)
{
    vector<int> path;

    if (root == NULL)
        return path;

    getPath(path, root, k);

    return path;
}


// https://www.interviewbit.com/problems/path-to-given-node/