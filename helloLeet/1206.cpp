// 设计跳表

constexpr int MAX_LEVEL = 16; // 共20000条数据，每次查找时的复杂度是k*n^(1/k)，当k = log_2^n时取极小值，20000对2取对数大概是14，15这样，取个整数16吧

struct Node{
    int val;
    vector<Node*> next; // 每一层的next，next[i]表示当前结点在第i层的next。这样的好处是，每个结点不需要在每一层都new一个，通过next数组将其指针分享给其他层。某个节点的某一层只和其他节点的同一层相连，通过cur = cur->next[i]在同一层移动，通过i++在节点内部的不同层之间移动
    Node(int _val) : val(_val), next(MAX_LEVEL, nullptr) {}
};

class Skiplist {
private:
    Node* head; // 左上角，作为哨兵
    mt19937 gen{random_device{}()}; // 硬件随机数（真随机数）作为种子
    uniform_int_distribution<int> dis{1, 2}; // 生成伪随机数（真随机数生成太慢了，而且有跨平台问题）
public:
    Skiplist() : head(new Node(-1)) {} // 数据都大于等于0，哨兵用-1就可以
    /*
    获取跳表中每一层，最后一个val小于target的结点，last_less[i]为第i层最后一个比less小的结点
    如果某层没有比less小的结点就放入哨兵
    */
    void helper(int target, vector<Node*>& last_less) {
        Node* cur = head;
        for (int i = MAX_LEVEL - 1; i >= 0; --i) {
            while (cur->next[i] != nullptr && cur->next[i]->val < target) cur = cur->next[i]; // 一直往右走，直到不能走了
            last_less[i] = cur; // 记录在该层走到最远的地方，即最后一个小于target的元素
            // --i去往下一层
        }
    }
    
    /*
    先做helper，然后访问第0层的next即可，因为第0层包含所有的元素，而last_less[0]则是第0层最后一个小于target的元素
    */
    bool search(int target) {
        vector<Node*> last_less(MAX_LEVEL, nullptr);
        helper(target, last_less);
        return last_less[0]->next[0] && last_less[0]->next[0]->val == target;
    }
    
    /*
    做helper之后一直往上插就行，根据每两个节点向上提升一次，每次从1，2之中取个随机数看做扔一次硬币，正面就提升
    */
    void add(int num) {
        vector<Node*> last_less(MAX_LEVEL, nullptr);
        helper(num, last_less);
        Node* new_node = new Node(num);
        for (int i = 0; i < MAX_LEVEL; ++i) {
            new_node->next[i] = last_less[i]->next[i];
            last_less[i]->next[i] = new_node;
            if (dis(gen) == 1) break; // 反面就跳出
        }
    }
    
    /*
    做helper之后，定位last_less[0]->next[0]看是不是num，不是就说明没有，返回false
    有的话一路删上去就行
    */
    bool erase(int num) {
        vector<Node*> last_less(MAX_LEVEL, nullptr);
        helper(num, last_less);
        Node* node = last_less[0]->next[0];
        if (!node || node->val != num) return false;
        for (int i = 0; i < MAX_LEVEL && last_less[i]->next[i] == node; ++i) last_less[i]->next[i] = node->next[i];
        delete node;
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
