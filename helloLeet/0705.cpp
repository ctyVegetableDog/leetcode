// Hash map
class MyHashSet {
    private:
        vector<list<int>> hash_vector;
        static const int div = 769;
        static int hash(int key) {
            return key % div;
        }
public:
    /** Initialize your data structure here. */
    MyHashSet() : hash_vector(div) {

    }
    
    void add(int key) {
        int h = hash(key);
        for (auto iter = hash_vector[h].begin(); iter != hash_vector[h].end(); ++iter) {
            if (*iter == key) return;
        }
        hash_vector[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto iter = hash_vector[h].begin(); iter != hash_vector[h].end(); ++iter) {
            if (*iter == key) {
                hash_vector[h].erase(iter);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for (auto iter = hash_vector[h].begin(); iter != hash_vector[h].end(); ++iter) {
            if (*iter == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
