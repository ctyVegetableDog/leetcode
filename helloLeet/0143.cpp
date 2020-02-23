//Reorder List

/*
	simple but typically question, contain find middle number in a list, reverse a list, and merge two lists
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
    
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {slow = slow->next; fast = fast->next->next; }
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        fast = head2->next;
        head2->next = nullptr;
        while (fast) {
            slow = fast->next;
            fast->next = head2;
            head2 = fast;
            fast = slow;
        }
        for (slow = head, fast = head2; slow && fast;) {
            auto p = slow->next;
            slow->next = fast;
            fast = fast->next;
            slow->next->next = p;
            slow = p;
        }
        return;
    }
};
