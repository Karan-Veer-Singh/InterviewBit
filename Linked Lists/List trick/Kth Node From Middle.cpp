/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int calcSize(ListNode *head)
{
    int n = 0;
    while (head)
    {
        n++;
        head = head->next;
    }
    return n;
}

int Solution::solve(ListNode* head, int k)
{
    int size = calcSize(head);
    int mid = (size / 2) + 1;
    k = mid - k;

    if (k <= 0)
        return -1;
    else
    {
        ListNode *temp = new ListNode(0);
        temp->next =  head;

        while (k--)
        {
            temp = temp->next;
        }

        return temp->val;
    }
}


// https://www.interviewbit.com/problems/kth-node-from-middle/