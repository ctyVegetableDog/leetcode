//swap node in chain table

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *m = res, *p = head, *q;
        while(p != NULL) {
            if (p -> next != NULL) {
                q = p->next;
                p->next = q ->next;
                q ->next = p;
                m->next = q;
                m = p;
                p = p->next;
            } else {
                m->next = p;
                break;
            }
        }
        return res->next;
    }
};
