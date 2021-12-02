// copy random list
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// 1.用hash来防止对节点的重复创建，当创建某节点时，先递归创建其next和random
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (mp.count(head) == 0) {
            Node* new_node = new Node(head->val);
            mp[head] = new_node;
            new_node->next = copyRandomList(head->next);
            new_node->random = copyRandomList(head->random);
        }
        return mp[head];
    }
};

//2.
//7->13->11->10->1
//先变成7->7->13->13->11->11->10->10->1->1
//然后对每个原链表里的数，其复制必然是其next，也就是说其复制的next的random就是其random的next
//最后再将两个链表分开
///*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *p = head;
        while (p) {
            Node* new_node = new Node(p->val);
            new_node->next = p->next;
            p->next = new_node;
            p = new_node->next;
        }

        p = head;
        while (p) {
            p->next->random = p->random ? p->random->next : nullptr;
            p = p->next->next;
        }
        p = head->next;
        Node *re_ori = head, *new_head = head->next;
        while (p->next) {
            re_ori->next = re_ori->next->next;
            p->next = p->next->next;
            re_ori = re_ori->next;
            p = p->next;
        }
        re_ori->next = nullptr;
        return new_head;
    }
};
