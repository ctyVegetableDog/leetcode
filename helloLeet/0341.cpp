// nested list iterator
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


// use dfs
class NestedIterator {
private:
    vector<int> vec;
    vector<int>::iterator iter;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (NestedInteger& ni : nestedList) {
            addToVec(ni);
        }
        iter = vec.begin();
    }
    void addToVec(NestedInteger& ni) {
        if (ni.isInteger()) {
            vec.push_back(ni.getInteger());
            return;
        } else {
            for (NestedInteger& sub_ni : ni.getList()) {
                addToVec(sub_ni);
            }
        }
    }
    
    int next() {
        return *(iter++);
    }
    
    bool hasNext() {
        return iter != vec.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
