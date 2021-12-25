/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Compare
{
public:
    bool operator()(ListNode *A, ListNode *B)
    {
        return A->val > B->val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A)
{
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;

    for (int i = 0; i < A.size(); i++)
        if (A[i] != NULL)
            pq.push(A[i]);

    while (!pq.empty())
    {
        ListNode *temp = pq.top();
        pq.pop();

        tail->next = temp;
        tail = temp;

        if (temp->next != NULL)
            pq.push(temp->next);
    }

    return dummy->next;
}


// https://www.interviewbit.com/problems/merge-k-sorted-lists/