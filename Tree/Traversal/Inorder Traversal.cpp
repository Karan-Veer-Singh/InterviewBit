/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* root)
{
    vector<int> inorder;
    stack<TreeNode*> s;
    TreeNode *node = root;

    while (true)
    {
        if (node != NULL)
        {
            s.push(node);
            node = node -> left;
        }
        else
        {
            if (s.empty())
                break;

            node = s.top();
            s.pop();

            inorder.push_back(node->val);

            node = node -> right;
        }
    }

    return inorder;
}


// https://www.interviewbit.com/problems/inorder-traversal/