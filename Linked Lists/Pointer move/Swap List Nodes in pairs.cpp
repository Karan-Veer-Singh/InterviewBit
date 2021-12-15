/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *curr = head;

    while (curr && curr->next)
    {
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev->next->next = curr;
        curr = curr->next;
        prev = prev->next->next;
    }

    return dummy->next;
}


// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/