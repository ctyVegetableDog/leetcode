//Remove Duplicates from Sorted List 2

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        if (!head->next->next) return head->val == head->next->val ? nullptr : head;
        ListNode *p, *q = head, *h = new ListNode(0);
        h->next = head;
        p = h;
        while (q) {
            while (q->next && q->val == q->next->val) q = q->next;
            if (p->next == q) p = q;
            else p->next = q->next;
            q = q->next;
        }
        return h->next;
    }
};
