/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(INT_MIN), right(INT_MIN) {}
 * };
 */

void inorder(TreeNode *root, int &prev, int &first, int &middle, int &last)
{
    if (root == NULL)    return;

    inorder(root->left, prev, first, middle, last);

    if (prev != INT_MIN && (root->val < prev))
    {
        if (first == INT_MIN)
        {
            first = prev;
            middle = root->val;
        }
        else
        {
            last = root->val;
        }
    }

    prev = root->val;

    inorder(root->right, prev, first, middle, last);
}

vector<int> Solution::recoverTree(TreeNode* root)
{
    int first = INT_MIN, middle = INT_MIN, last = INT_MIN, prev = INT_MIN;

    inorder(root, prev, first, middle, last);

    vector<int> ans;
    if (first != INT_MIN && last != INT_MIN)
    {
        ans.push_back(last);
        ans.push_back(first);
    }

    else if (first != INT_MIN && middle != INT_MIN)
    {
        ans.push_back(middle);
        ans.push_back(first);
    }

    return ans;
}


// https://www.interviewbit.com/problems/recover-binary-search-tree/