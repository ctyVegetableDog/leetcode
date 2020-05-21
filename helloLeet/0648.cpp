//Replace Words(Trie)

class Trie{
private:
    bool isEnd;
    Trie *next[26] = {};
public:
    Trie() {
        isEnd = false;
    }
    
    void insert(const string &s) {
        Trie *node = this;
        for (char ch : s) {
            if (!node->next[ch - 'a']) node->next[ch - 'a'] = new Trie();
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    string searchRoot(const string &s) {
        string res = "";
        Trie *root = this;
        for (char ch : s) {
            if (root->isEnd) return res;
            else {
                if (!root->next[ch - 'a']) return s;
                else {
                res += ch;
                root = root->next[ch - 'a'];
                }
            }
        }
        return s;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie *root = new Trie();
        for (auto s : dict) root->insert(s);
        string res = "", temp = "";
        for (char ch : sentence) {
            if (ch == ' ') {
                res.append(root->searchRoot(temp)).append(" ");
                temp = "";
            }
            else temp += ch;
        }
        res.append(root->searchRoot(temp));
        return res;
    }
};
