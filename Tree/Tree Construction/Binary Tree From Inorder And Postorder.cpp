/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* build(vector<int> &inOrder, int is, int ie, vector<int> &postOrder,
                int ps, int pe, unordered_map<int, int> &mp)
{
	if (ps > pe || is > ie)	return NULL;

	TreeNode *root = new TreeNode(postOrder[pe]);

	int ri = mp[postOrder[pe]];
	int numsLeft = ri - is;

	root->left = build(inOrder, is, ri - 1, postOrder, ps, ps + numsLeft - 1, mp);
	root->right = build(inOrder, ri + 1, ie, postOrder, ps + numsLeft, pe - 1, mp);

	return root;
}

TreeNode* Solution::buildTree(vector<int> &inOrder, vector<int> &postOrder)
{
	if (inOrder.size() != postOrder.size())
		return NULL;

	unordered_map<int, int> mp;

	for (int i = 0; i < inOrder.size(); i++)
		mp[inOrder[i]] = i;

	int iSize = inOrder.size();
	int pSize = postOrder.size();

	TreeNode *root = build(inOrder, 0, iSize - 1, postOrder, 0, pSize - 1, mp);

	return root;
}

// https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/