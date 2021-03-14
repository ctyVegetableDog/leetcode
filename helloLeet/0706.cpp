// hash map
class MyHashMap {
private:
    vector<list<pair<int, int>>> hash_vector;
    static const int div = 769;
    static int hash(int x) {
        return x % div;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() : hash_vector(div) {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);
        for (auto iter = hash_vector[h].begin(); iter != hash_vector[h].end(); ++iter) {
            if (iter->first == key) {
                iter->second = value;
                return;
            }
        }
        hash_vector[h].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key);
        for(auto iter = hash_vector[h].begin(); iter != hash_vector[h].end(); ++iter) {
            if(iter->first == key) return iter->second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        for (auto iter = hash_vector[h].begin(); iter != hash_vector[h].end(); ++iter) {
            if (iter->first == key) {
                hash_vector[h].erase(iter);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
