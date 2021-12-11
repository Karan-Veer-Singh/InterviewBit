/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A)
{
    ListNode *p1 = A;
    ListNode *p2 = A;

    while (p2 != NULL)
    {
        if (p2->val == 0)
        {
            swap(p1->val, p2->val);
            p1 = p1->next;
        }
        p2 = p2->next;
    }

    return A;
}


// https://www.interviewbit.com/problems/sort-binary-linked-list/