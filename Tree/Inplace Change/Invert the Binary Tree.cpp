/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* root)
{
	if (root == NULL)
		return NULL;

	invertTree(root -> left);
	invertTree(root -> right);

	swap(root -> left, root -> right);

	return root;
}

// Iterative

TreeNode* Solution::invertTree(TreeNode* root)
{
	if (root == NULL)
		return NULL;

	queue<TreeNode*> q;
	q.push(root);

	TreeNode *f;
	while (!q.empty())
	{
		f = q.front();
		q.pop();

		swap(f->left, f->right);

		if (f->left)
			q.push(f->left);

		if (f->right)
			q.push(f->right);
	}

	return root;
}

// https://www.interviewbit.com/problems/invert-the-binary-tree/