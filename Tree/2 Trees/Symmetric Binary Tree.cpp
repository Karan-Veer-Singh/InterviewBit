/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isMirror(TreeNode *root1, TreeNode *root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;

	if (root1 && root2 && root1->val == root2->val)
		return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);

	return false;
}

int Solution::isSymmetric(TreeNode* root)
{
	return isMirror(root, root);
}


// ITERATIVE

int Solution::isSymmetric(TreeNode* root)
{
	if (root == NULL)
		return true;

	queue<TreeNode*> q;

	q.push(root -> left);
	q.push(root -> right);

	TreeNode *leftNode, *rightNode;

	while (!q.empty())
	{
		leftNode = q.front();
		q.pop();

		rightNode = q.front();
		q.pop();

		if (leftNode == NULL && rightNode == NULL)
			continue;

		if (leftNode == NULL || rightNode == NULL || leftNode -> val != rightNode -> val)
			return false;

		q.push(leftNode -> left);   q.push(rightNode -> right);
		q.push(leftNode -> right);  q.push(rightNode -> left);
	}

	return true;
}

// https://www.interviewbit.com/problems/symmetric-binary-tree/