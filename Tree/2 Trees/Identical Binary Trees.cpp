/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Solution::isSameTree(TreeNode* A, TreeNode* B)
{
    if (A == NULL || B == NULL)
        return A == B;

    return (A->val == B->val && isSameTree(A->left, B->left) && isSameTree(A->right, B->right));
}

// Iterative

int Solution::isSameTree(TreeNode* root1, TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    queue<TreeNode*> q;

    q.push(root1);
    q.push(root2);

    TreeNode *temp1, *temp2;

    while (!q.empty())
    {
        temp1 = q.front();
        q.pop();

        temp2 = q.front();
        q.pop();

        if (temp1 == NULL && temp2 == NULL)
            continue;

        if (temp1 == NULL || temp2 == NULL || temp1->val != temp2->val)
            return false;

        q.push(temp1 -> left);  q.push(temp2 -> left);
        q.push(temp1 -> right); q.push(temp2 -> right);
    }

    return true;
}


// https://www.interviewbit.com/problems/identical-binary-trees/