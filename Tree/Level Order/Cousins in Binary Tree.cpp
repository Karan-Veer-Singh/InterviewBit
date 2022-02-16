/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root, int k)
{
    queue<TreeNode*> q;
    q.push(root);

    bool found = false;
    TreeNode *temp;

    while (!q.empty() && (found == false))
    {
        int size = q.size();
        while (size--)
        {
            temp = q.front();
            q.pop();

            if ( (temp->left && temp->left->val == k) || (temp->right && temp->right->val == k) )
                found = true;

            else
            {
                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
}


// https://www.interviewbit.com/problems/cousins-in-binary-tree/submissions/