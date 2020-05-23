//Camelcase Matching (Trie)

class Trie {
private:
    bool isEnd;
    Trie *next[58] = {};
public:
    Trie () {
        isEnd = false;
    }
    
    void insert(string s) {
        Trie *node = this;
        for (char ch : s) {
            if (!node->next[ch - 'A']) node->next[ch - 'A'] = new Trie();
            node = node->next[ch - 'A'];
        }
        node->isEnd = true;
    }
    
    bool search(string s) {
        Trie *node = this;
        for (char ch : s) {
            if (!node->next[ch - 'A']) {
                if (isupper(ch)) return false;
            } else {
                node = node->next[ch - 'A'];
            }
        }
        return node->isEnd;
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie *root = new Trie();
        root->insert(pattern);
        vector<bool> res;
        for (string s : queries) res.push_back(root->search(s));
        return res;
    }
};
