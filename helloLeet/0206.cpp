//reverse linked list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//normal solution with iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nh = NULL;
        ListNode *cur = head;
        while(cur) {
            ListNode *s = cur->next;
            cur->next = nh;
            nh = cur;
            cur = s;
        }
        return nh;
    }
};

//recursive version (p->next->next = p loooooool)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
