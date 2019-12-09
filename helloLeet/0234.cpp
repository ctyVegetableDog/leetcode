//reverse the list

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
    ListNode* rev(ListNode* head) {
        ListNode* pre = nullptr, *p;
        while(head) {
            p = head->next;
            head->next = pre;
            pre = head;
            head = p;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next;
        fast = head;
        slow = rev(slow);
        while(slow) {
            if (fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};
