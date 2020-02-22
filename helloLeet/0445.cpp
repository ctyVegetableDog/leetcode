//Add two number 2

/*
	reversing the lists is not allowed (but still using stack at 1st solution)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//using stack (not allow)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr;
        stack<int> st1, st2;
        int sum = 0, rem = 0;
        while (l1) {st1.push(l1->val); l1 = l1->next;}
        while (l2) {st2.push(l2->val); l2 = l2->next;}
        while (!st1.empty() || !st2.empty()) {
            if (!st1.empty()) {sum += st1.top(); st1.pop();}
            if (!st2.empty()) {sum += st2.top(); st2.pop();}
            sum += rem;
            ListNode *node = new ListNode(sum % 10);
            rem = sum / 10;
            sum = 0;
            node->next = res;
            res = node;
        }
        if (rem) {
            ListNode *h = new ListNode(rem);
            h->next = res;
            res = h;
        }
        return res;
    }
};

/*
	reverse the output
*/

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
    ListNode* addToFront(int val, ListNode* head) {
        ListNode *node = new ListNode(val);
        node->next =head;
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr, *p = l1, *q = l2, *h = nullptr;
        int carry = 0, len1 = 0, len2 = 0;
        while (p) {len1++; p = p->next; }
        while (q) {len2++; q = q->next; }
        while (len1 || len2) {
            if (len1 > len2) { res = addToFront(l1->val, res); l1 = l1->next; len1--;}
            else if (len2 > len1) { res = addToFront(l2->val, res); l2 = l2->next; len2--;}
            else {res = addToFront(l1->val + l2->val, res); l1 = l1->next; len1--; l2 = l2->next; len2--;}
        }
        while (res) {
            q = res->next;
            res->val += carry;
            carry = res->val / 10;
            res->val %= 10;
            res->next = h;
            h = res;
            res = q;
        }
        if (carry) h = addToFront(1, h);
        return h;
    }
};
