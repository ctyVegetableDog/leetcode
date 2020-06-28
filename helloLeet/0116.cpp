//Populating Next Right Pointers in Each Node

/*
just traverse the prefect binary tree in level order
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* start = root;
        while (start) {
            Node* cur = start;
            while (cur) {
                if (cur->left) cur->left->next = cur->right;
                if (cur->right && cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            start = start->left;
        }
        return root;
    }
};
