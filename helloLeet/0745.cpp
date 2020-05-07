//Trie (should have better solution)

class Trie {
private:
    vector<int> word_index;
    vector<Trie*> children;
    
public:
    Trie() {
        children = vector<Trie*>(26, nullptr);
    }
    ~Trie() {
        for (int i = 0; i < 26; ++i) {
            if (children[i]) {
                delete(children[i]);
            }
        }
    }
    void add(const string &word, int begin, int index) {
        word_index.push_back(index);
        if (begin < word.length()) {
            if (!children[word[begin] - 'a']) {
                children[word[begin] - 'a'] = new Trie();
            }
            children[word[begin] - 'a']->add(word, begin + 1, index);
        }
    }
    vector<int> find(const string &prefix, int begin) {
        if (begin == prefix.length()) return word_index;
        else {
            if (!children[prefix[begin] - 'a']) return {};
            return children[prefix[begin] - 'a']->find(prefix, begin + 1);
        }
    }
};


class WordFilter {
private:
    Trie *forward, *backward;
public:
    WordFilter(vector<string>& words) {
        forward = new Trie();
        backward = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            forward->add(s, 0, i);
            reverse(s.begin(), s.end());
            backward->add(s, 0, i);
        }
    }
    
    int f(string prefix, string suffix) {
        auto forward_res = forward->find(prefix, 0);
        reverse(suffix.begin(), suffix.end());
        auto backward_res = backward->find(suffix, 0);
        for (auto fiter = forward_res.rbegin(), biter = backward_res.rbegin(); fiter != forward_res.rend() && biter != backward_res.rend();) {
            if (*fiter == *biter) return *fiter;
            else if (*fiter > *biter) ++fiter;
            else ++biter;
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
