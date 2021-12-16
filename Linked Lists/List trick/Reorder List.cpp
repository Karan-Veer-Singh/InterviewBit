/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* getMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* reverse(ListNode *curr)
{
    ListNode *prev = NULL;
    ListNode *nextNode;

    while (curr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

ListNode* Solution::reorderList(ListNode* head)
{
    if (head == NULL)
        return head;

    ListNode *mid = getMiddle(head);

    ListNode *first = head;
    ListNode *second = reverse(mid);
    ListNode *temp;

    while (second->next != NULL)
    {
        temp = first->next;
        first->next = second;
        first = temp;

        temp = second->next;
        second->next = first;
        second = temp;
    }

    return head;
}


// https://www.interviewbit.com/problems/reorder-list/