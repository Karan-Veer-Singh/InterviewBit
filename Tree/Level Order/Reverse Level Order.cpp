/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root)
{
	vector<int> ans;

	if (root == NULL)    return ans;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		root = q.front();
		q.pop();

		ans.push_back(root -> val);

		if (root -> right)   q.push(root -> right);
		if (root -> left)    q.push(root -> left);

	}

	reverse(ans.begin(), ans.end());
	return ans;
}
