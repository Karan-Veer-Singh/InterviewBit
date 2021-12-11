/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    ListNode *start = new ListNode(0);
    start->next = head;

    ListNode *slow = start;
    ListNode *fast = start;

    for (int i = 1; i <= n; i++)
    {
        fast = fast->next;

        if (fast == NULL)
            return head->next;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return start->next;
}


// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/