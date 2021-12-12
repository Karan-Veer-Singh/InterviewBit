/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* head)
{
    ListNode *zeroD = new ListNode(0);
    ListNode *oneD = new ListNode(0);

    ListNode *zero = zeroD;
    ListNode *one = oneD;

    while (head != NULL)
    {
        if (head->val == 0)
        {
            zero->next = head;
            zero = zero->next;
        }
        else
        {
            one->next = head;
            one = one->next;
        }

        head = head->next;
    }

    zero->next = (oneD->next) ? (oneD->next) : NULL;
    one->next = NULL;

    head = zeroD->next;

    delete zeroD;
    delete oneD;

    return head;
}


//