//Insert Delete GetRandom O(1) - Duplicates allowed (hash map)

class RandomizedCollection {
private:
    unordered_map<int, vector<int> > mp;
    vector<pair<int, int> > v;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = mp.find(val) == mp.end();
        mp[val].push_back(v.size());
        v.push_back(pair<int, int>(val, mp[val].size() - 1));
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool res = mp.find(val) != mp.end();
        if (res) {
            auto pos = v.back();
            mp[pos.first][pos.second] = mp[val].back();
            v[mp[val].back()] = pos;
            v.pop_back();
            mp[val].pop_back();
            if (mp[val].empty()) mp.erase(val);
        }
        return res;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand() % v.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
