//one way

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *res = new ListNode(0);
        res ->next = head;
        ListNode *p = res, *q = res;
        for (int i = 0; i <= n;i ++) q = q->next;
        while (q != NULL) {
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return res->next;
    }
};
