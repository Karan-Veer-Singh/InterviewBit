/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root)
{
    vector<int> diagonal;

    if (!root)
        return diagonal;

    queue<TreeNode*> q;
    q.push(root);

    TreeNode *curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        while (curr)
        {
            diagonal.push_back(curr->val);

            if (curr->left)
                q.push(curr->left);

            curr = curr->right;
        }
    }

    return diagonal;
}


// https://www.interviewbit.com/problems/diagonal-traversal/