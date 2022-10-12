// 链表组建


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
 *并查集
 捞得都淌口水
 * */
class Solution {
public:
    int getParent(vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        else return getParent(parent, parent[i]);
    }

    // a结点的老大给b结点老大当小弟
    void unionParent(vector<int>& parent, int a, int b) {
        parent[getParent(parent, a)] = getParent(parent, b);
    }

    int numComponents(ListNode* head, vector<int>& nums) {
        if (nums.size() <= 1) return 1;
        int len_nums = nums.size();
        vector<int> parent(10005, -1); // 每个结点的老大
        unordered_map<int, pair<int, int>> neighour; // 每个结点的邻居
        int len_head = 0, pre = -1;
        ListNode* p = head;
        while(p != nullptr) {
            parent[p->val] = p->val; // 每个结点老大是他自己
            neighour[p->val].first = pre; // 左边邻居的值
            neighour[p->val].second = p->next ? p->next->val : -1; // 右边领居
            pre = p->val;
            p = p->next;
        }
        int ans = 0;
        vector<bool> visited(10005, false); // 每个结点是否已经被访问
        for (int i = 0; i < len_nums; ++i) {
            visited[nums[i]] = true;
            int left = neighour[nums[i]].first, right = neighour[nums[i]].second;
            if (left == -1) { // 没左邻居
                if (!visited[right]) ++ans;
                else parent[nums[i]] = getParent(parent, right);
            } else if (right == -1) { // 没右邻居
                if (!visited[left]) ++ans;
                else parent[nums[i]] = getParent(parent, left);
            } else { // 左右邻居都有
                if (!visited[left] && !visited[right]) ++ans;
                else if (visited[left] && !visited[right]) parent[nums[i]] = getParent(parent, left);
                else if (!visited[left] && visited[right]) parent[nums[i]] = getParent(parent, right);
                else {
                    parent[nums[i]] = getParent(parent, left);
                    unionParent(parent, right, left);
                    --ans;
                }
            }
        }
        return ans;

    }
};

/*
 *官方题解：
 一个结点是组件的开头，当其满足任意一个：
 1.是链表的开头，且在nums中
 2.其前一个结点不在nums中
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> us;
        for (int i : nums) {
            us.emplace(i);
        }
        ListNode* p = head;
        int ans = 0;
        bool pre_in_set = false;
        while(p) {
            if (us.count(p->val)) {
                if (p == head || !pre_in_set) {
                    ++ans;
                } pre_in_set = true;
            } else pre_in_set = false;
            p = p->next;
        }
        return ans;
    }
};
