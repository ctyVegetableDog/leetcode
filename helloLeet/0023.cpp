//merge them one by one, priority queue could be better solution
//and when I change it ot divide and conquer, it become slower, but technically, it should be O(kn)-> O(nlogk)

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
    ListNode* mergeTwo(ListNode* l1, ListNode *l2) {
        ListNode *res = new ListNode(0);
        ListNode *p = l1, *q = l2, *t = res;
        while(p != NULL && q != NULL) {
            if (p->val >= q->val) {
                t ->next = q;
                q = q ->next;
                t = t->next;
            } else {
                t ->next = p;
                p = p->next;
                t = t->next;
            }
        }
        if (p != NULL) t->next = p;
        if (q != NULL) t->next = q;
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int l = lists.size();
        ListNode *res = lists[0];
        for (int i = 1;i < l; i ++) res = mergeTwo(res,lists[i]);
        return res;
    }
};
