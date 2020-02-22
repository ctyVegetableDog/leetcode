//Next Greater Node in Linked List

/*
	Just convert list to array, and it's become next greater element
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> st;
        for (auto p = head; p; p = p->next) {
            while (!st.empty() && res[st.top()] < p->val) {
                res[st.top()] = p->val;
                st.pop();
            }
            st.push(res.size());
            res.push_back(p->val);
        }
        while (!st.empty()) { res[st.top()] = 0; st.pop(); }
        return res;
    }
};
