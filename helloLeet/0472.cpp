//Concatenated Words

/*
	Trie + DP become tooooooooo slow -.-
*/

class Trie {
private:
    bool isEnd;
    Trie *next[26] = {};
public:
    Trie () {
        isEnd = false;
    }
    
    void insert(string s) {
        Trie *node = this;
        for (char ch : s) {
            if (!node->next[ch - 'a']) node->next[ch -  'a'] = new Trie();
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string s) {
        Trie *node = this;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (!node->next[ch - 'a']) return false;
            node = node->next[ch - 'a'];
        }
        return node->isEnd;
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie *root = new Trie();
        vector<string> res;
        for (string s : words) {
            root->insert(s);
        }
        for (string s : words) {
            if (s.size() == 0) continue;
            vector<bool> dp(s.size(),false);
            int cnt = 0;
            dp[0] = root->search(s.substr(0, 1));
            if (dp[0] && s.size() > 1) ++cnt;
            for (int i = 1; i < s.size(); ++i) {
                if (i < s.size() - 1 && root->search(s.substr(0, i + 1))) {
                    dp[i] = true;
                    ++cnt;
                    continue;
                }
                for (int j = 1; j <= i; ++j) {
                    if (dp[i - j] && root->search(s.substr(i - j + 1, j))) {
                        dp[i] = true;
                        ++cnt;
                        break;
                    }
                }
            }
            if (dp[s.size() - 1] && (cnt > 1)) res.push_back(s);
        }
        return res;
    }
};
