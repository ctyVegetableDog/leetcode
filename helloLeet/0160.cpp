//two points

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0, l2 = 0;
        ListNode *p = headA, *q = headB;
        while (p) {
            l1++;
            p = p->next;
        }
        while (q) {
            l2++;
            q = q->next;
        }
        p = headA;
        q = headB;
        while (l1 != l2) {
            if (l1 > l2) {
                l1--;
                p = p->next;
            }
            else{
                l2--;
                q = q->next;
            }
            if (p == q) return p;
        }
        while(p && q) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};
