//Flatten a Multilevel Doubly Linked List

/*
	just like traverse a binary tree
	but don't know why it's so slow, it's O(n) and I can't figure out beter solution
	and I use recursion as well ws an additional vection but still beat 100% in space perspective(.-.)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
private:
    vector<Node*> v;
public:
    void helper(Node* head) {
        if (!head) return;
        v.push_back(head);
        helper(head->child);
        helper(head->next);
    }
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        helper(head);
        Node* nh = v[0], *p = nh;
        for (int i = 1; i < v.size(); i++) {
            p->next = v[i];
            p->child = nullptr;
            v[i]->prev = p;
            p = p->next;
        }
        return nh;
    }
};
