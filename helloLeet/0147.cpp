//Insertion Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *h = new ListNode(0), *p = head, *q, *temp;
        q = h;
        while (p) {
            while (q->next && p->val > q->next->val) q = q->next;
            temp = p->next;
            p->next = q->next;
            q->next = p;
            p = temp;
            q = h;
        }
        return h->next;
    }
};
