// 并查集

class Solution {
public:
    /*
    用并查集找环
    如果某条边的两个端点属于不同的集合，那么说明添加它不会产生环，否则会产生
    */

    // 查：查找某个结点的根结点
    int getParent(vector<int>& parent, int number) {
        if (parent[number] == number) return number; // 根结点的根是它自己返回
        else return getParent(parent, parent[number]); //否则往上寻找返回其父节点的根
    }

    // 并：合并两个集合，其中一个结点的根结点成为另一个的子结点
    void unionParent(vector<int>& parent, int a, int b) {
        parent[getParent(parent, a)] = getParent(parent, b);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        vector<int> parent(len + 1);
        for (int i = 1; i <= len; ++i) parent[i] = i; // 初始化并查集，开始时每个结点的根结点都是它自己，也就是说每个结点自己是一个集合
        vector<int> ans(2);
        for (auto& e : edges) {
            if (getParent(parent, e[0]) == getParent(parent, e[1])) { // 成环
                ans[0] = e[0]; ans[1] = e[1];
            } else { //否则合并集合
                unionParent(parent, e[0], e[1]);
            }
        }
        return ans;
    }
};
