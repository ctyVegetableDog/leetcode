//Odd Even Linked List

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *p = head, *nh = new ListNode(0), *q = nh;;
        while (p && p->next) {
            q->next = p->next;
            p->next = p->next->next;
            if (p->next) p = p->next;
            q = q->next;
        }
        q->next = nullptr;
        p->next = nh->next;
        return head;
    }
};
