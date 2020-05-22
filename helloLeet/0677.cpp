//Map Sum Pairs (Trie)

/*
	Just call me the king of Trie
	高兴滴说中文
*/

class Trie {
private:
    bool isEnd;
    int cnt;
    Trie *next[26] = {};
public:
    Trie() {
        isEnd = false;
        cnt = 0;
    }
    
    void insert(string key, int val, int already_exist) {
        Trie *node = this;
        for (char ch : key) {
            if (!node->next[ch - 'a']) node->next[ch - 'a'] = new Trie();
            node = node->next[ch - 'a'];
            node->cnt -= already_exist;
            node->cnt += val;
        }
        node->isEnd = true;
    }
    
    int sum(string prefix) {
        Trie *node = this;
        int num = -1;
        for (char ch : prefix) {
            if (!node->next[ch - 'a']) return 0;
            node = node->next[ch - 'a'];
            num = node->cnt;
        }
        return num;
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        root->insert(key, val, mp[key]);
        mp[key] = val;
    }
    
    int sum(string prefix) {
        return root->sum(prefix);
    }
private:
    Trie *root;
    unordered_map<string, int> mp;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
