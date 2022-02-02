/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode *root)
{
	if (root == NULL)
		return 0;

	int lh = height(root -> left);
	if (lh == -1)    return -1;

	int rh = height(root -> right);
	if (rh == -1)    return -1;

	if (abs(lh - rh) > 1)    return -1;

	return 1 + max(lh, rh);
}

int Solution::isBalanced(TreeNode* root)
{
	return height(root) != -1;
}


// https://www.interviewbit.com/problems/balanced-binary-tree/