/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B)
{
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;
    int carry = 0;

    while (A || B || carry)
    {
        int sum = 0;
        if (A)
        {
            sum += A->val;
            A = A->next;
        }

        if (B)
        {
            sum += B->val;
            B = B->next;
        }

        sum += carry;
        carry = sum / 10;

        ListNode *newNode = new ListNode(sum % 10);
        temp->next = newNode;
        temp = temp->next;
    }

    return dummy->next;
}


// https://www.interviewbit.com/problems/add-two-numbers-as-lists/