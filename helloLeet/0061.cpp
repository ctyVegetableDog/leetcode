//rotate list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int len = 1;
        ListNode *p, *q;
        p = q = head;
        while (q->next) {
            len++;
            q = q->next;
        }
        q->next = head;
        if (k %= len) {
            for (int i = 0; i < len - k; i++) q = q->next;
        }
        p = q->next;
        q->next = nullptr;
        return p;
    }
};
