//Split linked list in parts

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k, nullptr);
        ListNode *p = root, *q = nullptr;
        int len = 0, x = 0, y = 0, n, m;
        while (p) {
            len++;
            p = p->next;
        }
        n = len % k;//number of sets need to + 1 node
        m = len / k;//nodes per set
        p = root;
        for (int i = 0;p && i < k; i++, n--) {
            res[i] = p;
            for (int j = 0; j < m + (n > 0); j++) {
                q = p;
                p = p->next;
            }
            q->next = nullptr;
        }
        return res;
    }
};
