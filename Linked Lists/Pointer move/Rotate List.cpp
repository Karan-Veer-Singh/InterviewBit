/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    ListNode *curr = head;
    int length = 1;
    while (curr->next)
    {
        curr = curr->next;
        length++;
    }

    curr->next = head;
    k = k % length;
    k = length - k;

    while (k--)
    {
        curr = curr->next;
    }

    head = curr->next;
    curr->next = NULL;

    return head;
}


// https://www.interviewbit.com/problems/rotate-list/