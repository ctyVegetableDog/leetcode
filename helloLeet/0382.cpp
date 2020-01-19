//reservoir samnpling (interesting question)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *h;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        h = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = 1;
        int res = -1;
        ListNode *p = h;
        while (p) {
            int r = rand() % n + 1;
            if (r == 1) res = p->val;
            p = p->next;
            n++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
