/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head)
{
    if (!head || !head->next)
        return head;

    ListNode *temp = head;
    while (temp->next)
    {
        if (temp->val == temp->next->val)
        {
            ListNode *del = temp->next;
            temp->next = del->next;
            delete del;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}


// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/