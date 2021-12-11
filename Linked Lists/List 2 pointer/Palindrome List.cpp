/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverse(ListNode *curr)
{
    ListNode *prev = NULL;
    ListNode *next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int Solution::lPalin(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return 1;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;

    while (slow != NULL)
    {
        if (head->val != slow->val)
            return 0;

        slow = slow->next;
        head = head->next;
    }

    return 1;
}


// https://www.interviewbit.com/problems/palindrome-list/