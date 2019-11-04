//two pointers


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *p = l1, *q = l2, *t = res;
        while(p != NULL && q != NULL) {
            if (p->val >= q->val) {
                t ->next = q;
                q = q ->next;
                t = t->next;
            } else {
                t ->next = p;
                p = p->next;
                t = t->next;
            }
        }
        if (p != NULL) t->next = p;
        if (q != NULL) t->next = q;
        return res->next;
    }
};
