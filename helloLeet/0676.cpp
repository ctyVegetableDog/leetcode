//Implement Magic Dictionary (Trie)

class Trie {
public:
    Trie *next[26] = {};
    bool isEnd;
    Trie () {
        isEnd = false;
    }
    
    void insert(string s) {
        Trie *node = this;
        for (char ch : s) {
            if (!node->next[ch - 'a']) node->next[ch - 'a'] = new Trie();
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string s) {
        Trie *node = this;
        for (char ch : s) {
            if (!node->next[ch - 'a']) return false;
            node = node->next[ch - 'a'];
        }
        return node->isEnd;
    }
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new Trie();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const string &s : dict) {
            root->insert(s);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        Trie *node = this->root;
        for (int i = 0; i < word.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                if ('a' + j != word[i] && node->next[j]) {
                    char temp = word[i];
                    word[i] = 'a' + j;
                    if (helper(i, word, node)) return true;
                    word[i] = temp;
                }
            }
            if (!node->next[word[i] - 'a']) return false;
            node = node->next[word[i] - 'a'];
        }
        return false;
    }
    
    bool helper(int i, string word, Trie *node) {
        for (; i < word.size(); ++i) {
            if (!node->next[word[i] - 'a'] || !node) return false;
            node = node->next[word[i] - 'a'];
        }
        return node->isEnd;
    }
private:
    Trie *root;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
