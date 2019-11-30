//Trie (a little bit slow)

class TrieNode {
public:
    TrieNode* next[26] = {};
    bool isEnd;
    TrieNode() {isEnd = false;}
    bool search(string word, int pos, TrieNode* root) {
        if (pos == word.size()) return root->isEnd;
        if (word[pos] != '.') {
            root = root->next[word[pos] - 'a'];
            return root ? search(word, pos + 1, root) : false;
        }
        for (int i = 0; i < 26; i ++) {
            if (root->next[i] && search(word,pos + 1, root->next[i]))
                return true;
        } 
        return false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* rt = this->root;
        for (char ch : word) {
            ch -= 'a';
            if (!rt->next[ch]) rt->next[ch] = new TrieNode();
            rt = rt->next[ch];
        }
        rt->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return this->root->search(word, 0, this->root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
