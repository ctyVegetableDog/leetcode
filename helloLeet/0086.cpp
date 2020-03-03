//Partition List

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = new ListNode(0), *h2 = new ListNode(0), *p = h1, *q = h2;
        while (head) {
            if (head->val >= x) p = p->next = head;
            else q = q->next = head;
            head = head->next;
        }
        p->next = nullptr;
        q->next = h1->next;
        return h2->next;
    }
};
