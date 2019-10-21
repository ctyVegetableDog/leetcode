//point

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *res, *p;
        bool ok = true;
        while (l1 != NULL || l2 != NULL || sum > 0) {
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode *n = new ListNode(sum % 10);
            sum /= 10;
            if (ok) {
                res = n;
                p = n;
                ok = !ok;
            } else {
                p->next = n;
                p = p->next;
            }
        }
        return res;
    }
};
