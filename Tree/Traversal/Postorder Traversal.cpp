/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* root)
{
    vector<int> postorder;

    if (root == NULL)
        return postorder;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty())
    {
        root = s.top();
        s.pop();

        postorder.push_back(root->val);

        if (root -> left)
            s.push(root -> left);

        if (root -> right)
            s.push(root -> right);
    }

    reverse(postorder.begin(), postorder.end());

    return postorder;
}


// https://www.interviewbit.com/problems/postorder-traversal/