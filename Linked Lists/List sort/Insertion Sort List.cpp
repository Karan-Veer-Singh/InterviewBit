/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void sortedInsert(ListNode* &head, ListNode *newNode)
{
    if (head == NULL || newNode->val <= head->val)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ListNode *temp = head;
        while (temp->next != NULL && temp->next->val < newNode->val)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

ListNode* Solution::insertionSortList(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = head;
    ListNode *sorted = NULL;

    while (temp != NULL)
    {
        ListNode *next = temp->next;
        sortedInsert(sorted, temp);
        temp = next;
    }

    return head = sorted;
}


// https://www.interviewbit.com/problems/insertion-sort-list/