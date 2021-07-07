// reverseKGroup
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto h = head;
        for (int i = 0; i < k; ++i) {
            if (!h) return head;
            h = h->next;
        }
        auto  res = reverseOneGroup(head, h);
        head->next = reverseKGroup(h, k);
        return res;
    }
    ListNode* reverseOneGroup(ListNode* left, ListNode* right) {
        auto pre = right;
        while (left != right) {
            auto node = left->next;
            left->next = pre;
            pre = left;
            left = node;
        }
        return pre;
    }
};
