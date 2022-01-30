/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* root)
{
    vector<int> preorder;

    if (root == NULL)
        return preorder;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty())
    {
        root = s.top();
        s.pop();

        preorder.push_back(root->val);

        if (root -> right)
            s.push(root -> right);

        if (root -> left)
            s.push(root -> left);
    }

    return preorder;
}


// https://www.interviewbit.com/problems/preorder-traversal/