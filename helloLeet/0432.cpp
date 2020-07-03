//All O' one Data Structure (hash)

class AllOne {
private:
    struct Bucket { int val; unordered_set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> keyToBucket;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        //if key is not exist
        if (!keyToBucket.count(key)) {
            keyToBucket[key] = buckets.insert(buckets.begin(), {0, {key}});
        }
        //move key to new bucket
        auto next = keyToBucket[key], cur = next++;
        if (next == buckets.end() || next->val > cur->val + 1) {
            next = buckets.insert(next, {cur->val + 1, {}});
        }
        next->keys.insert(key);
        //remove key from old bucket
        keyToBucket[key] = next;
        cur->keys.erase(key);
        if (cur->keys.empty()) {
            buckets.erase(cur);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!keyToBucket.count(key)) return;
        
        auto prev = keyToBucket[key], cur = prev--;
        keyToBucket.erase(key);
        
        if (cur->val > 1) {
            if (cur == buckets.begin() || prev->val < cur->val - 1) {
                prev = buckets.insert(cur, {cur->val - 1, {}});
            }
        
            prev->keys.insert(key);
            keyToBucket[key] = prev;
        }
        
        cur->keys.erase(key);
        if (cur->keys.empty()) {
            buckets.erase(cur);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
