// 设计链表

//很不错的巩固基础的题，题目很简单，但是细节不少，值得多看几遍

class Node{
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr){}
    Node() : val(0), next(nullptr) {}
};

class MyLinkedList {
private:
    Node* head;
    int length;
public:
    MyLinkedList() {
        head = new Node();
        length = 0;
    }
    
    int get(int index) {
        if (index >= length) return -1;
        Node* idx = head->next;
        while(index--) {
            idx = idx->next;
        }
        return idx->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head->next;
        head->next = node;
        ++length;
    }
    
    void addAtTail(int val) {
        Node* idx = head;
        while (idx->next != nullptr) idx = idx->next;
        Node* node = new Node(val);
        idx->next = node;
        ++length;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) addAtHead(val);
        else if (index > length) return;
        else if (index == length) addAtTail(val);
        else {
            Node* idx = head;
            while(index--) idx = idx->next;
            Node* node = new Node(val);
            node->next = idx->next;
            idx->next = node;
            ++length;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if (index >= length || index < 0) return;
        Node* idx = head;
        while (index--) {
            idx = idx->next;
        }
        idx->next = idx->next->next;
        --length;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
