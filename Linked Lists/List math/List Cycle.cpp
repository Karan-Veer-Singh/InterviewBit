/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head)
{
    if (head == NULL || head -> next == NULL)
        return NULL;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast -> next && fast -> next -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;

        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow -> next;
                fast = fast -> next;
            }

            return slow;
        }
    }

    return NULL;
}


// https://www.interviewbit.com/problems/list-cycle/