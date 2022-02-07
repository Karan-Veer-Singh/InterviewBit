/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool find(TreeNode *root, int k)
{
	if (root == NULL)   return false;

	if (root->val == k)  return true;

	return (find(root->left, k) || find(root->right, k));
}

int findLca(TreeNode* root, int a, int b)
{
	if (root == NULL)
		return -1;

	if (root->val == a || root->val == b)
		return root->val;

	int left = findLca(root->left, a, b);
	int right = findLca(root->right, a, b);

	if (left == -1)
		return right;

	else if (right == -1)
		return left;

	else
		return root->val;
}

int Solution::lca(TreeNode* root, int a, int b)
{
	if (find(root, a) == false || find(root, b) == false)
		return -1;

	return findLca(root, a, b);
}


// https://www.interviewbit.com/problems/least-common-ancestor/