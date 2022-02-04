/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* root, int k)
{
    stack<TreeNode*> s;
    int c = 0;

    while (true)
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            if (s.empty())   break;

            root = s.top();
            s.pop();

            c++;
            if (c == k)      return root->val;

            root = root->right;
        }
    }

    return -1;
}


// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/