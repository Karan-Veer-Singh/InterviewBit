/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

pair<ListNode*, ListNode*> reverse(ListNode *curr, int count)
{
    ListNode *prev = NULL;
    ListNode *nextNode;

    while (count--)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return {prev, nextNode};
}

ListNode* Solution::reverseBetween(ListNode* head, int m, int n)
{
    if (head == NULL || head->next == NULL || m == n)
        return head;

    ListNode *beforeStart = NULL;
    ListNode *start = head;

    for (int i = 1; i < m; i++)
    {
        beforeStart = start;
        start = start->next;
    }

    pair<ListNode*, ListNode*> p = reverse(start, n - m + 1);
    ListNode *end = p.first;
    ListNode *beforeEnd = p.second;

    if (beforeStart != NULL)
        beforeStart->next = end;
    else
        head = end;

    start->next = beforeEnd;
    return head;
}


// https://www.interviewbit.com/problems/reverse-link-list-ii/