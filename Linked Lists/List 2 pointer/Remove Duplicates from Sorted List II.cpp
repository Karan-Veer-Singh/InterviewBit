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
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;

    while (head)
    {
        if (head->next != NULL && head->val == head->next->val)
        {
            while (head->next != NULL && head->val == head->next->val)
            {
                head = head->next;
            }
            prev->next = head->next;
        }
        else
        {
            prev = prev->next;
        }

        head = head->next;
    }

    return dummy->next;
}


// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/