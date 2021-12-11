/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B)
{
    if (A == NULL || B == NULL)
        return NULL;

    ListNode *a = A;
    ListNode *b = B;

    while (a != b)
    {
        a = a == NULL ? B : a->next;
        b = b == NULL ? A : b->next;
    }

    return a;
}


// https://www.interviewbit.com/problems/intersection-of-linked-lists/