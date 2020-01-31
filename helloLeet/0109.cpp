//Convert sorted list to BST

/*
	Convert a sorted list to a balanced BST, I thouught it's about AVL but it's not
	The solution is simple but hard to describe, just look the website T T
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* p;
    TreeNode* generate(int len) {
        if (len == 0) return nullptr;
        TreeNode* node = new TreeNode(0);
        node->left = generate(len/2);
        node->val = p->val;
        p = p->next;
        node->right = generate(len - len/2 - 1);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        p = head;
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return generate(len);
    }
};
