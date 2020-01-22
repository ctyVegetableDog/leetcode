//Remove zero sum consecutive nodes from linked list (hash map)

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* root = new ListNode(0);
        root->next = head;
        unordered_map<int, ListNode*> mp;
        mp[0] = root;
        int cur = 0;
        while (head) {
            cur += head->val;
            if (mp.find(cur) != mp.end()) {
                ListNode *p = mp[cur], *q = mp[cur];
                int de = cur;
                while (q != head) {
                    q = q->next;
                    de += q->val;
                    if (q != head) mp.erase(de);
                }
                p->next = head->next;
            } else {
                mp[cur] = head;
            }
            head = head->next;
        }
        return root->next;
    }
};
