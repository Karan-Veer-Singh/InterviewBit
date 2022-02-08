/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* root, int sum)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return (sum - root->val) == 0;

	return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
}


// https://www.interviewbit.com/problems/path-sum/