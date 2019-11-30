//Trie (prefix tree) very important structure


//if we take an Trie object as a whole tree, it could be too slow and cost too much memory
class Trie {
private:
    vector<vector<int> > tr;
    vector<bool> isEnd;//isEnd[i] means whether the prefix end with i is a word
    int cur;
public:
    /** Initialize your data structure here. */
    Trie() {
        cur = 0;
        vector<int> nv(26,0);
        tr.push_back(nv);
        isEnd.push_back(false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int l = word.size();
        int root = 0;
        for (int i = 0; i < l; i++) {
            int id = word[i] - 'a';
            if (tr[root][id] == 0) {
                tr[root][id] = ++cur;
                isEnd.push_back(false);
                vector<int> nv(26,0);
                tr.push_back(nv);
            }
            root = tr[root][id];
        }
        isEnd[root] = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int l = word.size();
        int root = 0;
        for (int i = 0; i < l; i++) {
            int id = word[i] - 'a';
            if (tr[root][id] == 0) return false;
            root = tr[root][id];
        }
        return isEnd[root];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int l = prefix.size();
        int root = 0;
        for (int i = 0; i < l; i++) {
            int id = prefix[i] - 'a';
            if (tr[root][id] == 0) return false;
            root = tr[root][id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


//so we have to take an Trie object as a node
class Trie {
private:
    bool isEnd;
    Trie* next[26] = {};
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) { node->next[ch] = new Trie(); }
            node = node->next[ch];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for (char ch : word) {
            ch -= 'a';
            if (!root->next[ch]) return false;
            root = root->next[ch];
        }
        return root->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (!root->next[ch]) return false;
            root = root->next[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
