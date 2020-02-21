//Reverse Linked List 2

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *temp_h = nullptr, *q = head, *fake_head = new ListNode(0), *p = fake_head, *t, *r;
        fake_head->next = head;
        m--;
        n -= m;
        while (p && m--) {
            p = p->next;
        }
        q = p->next;
        r = p->next;
        while (q && n--) {
            t = q->next;
            q->next = temp_h;
            temp_h = q;
            q = t;
        }
        p->next = temp_h;
        r->next = t;
        return fake_head->next;
    }
};
