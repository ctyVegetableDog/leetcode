// serialize and deserialize BT
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void shelper(TreeNode* root, string& st) {
        if (!root) {
            st += "N,";
        } else {
            st += to_string(root->val) + ",";
            shelper(root->left, st);
            shelper(root->right, st);
        }
    }

    string serialize(TreeNode* root) {
        string st;
        shelper(root, st);
        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode* dshelper(list<string>& tree_data) {
        if (tree_data.front() == "N") {
            tree_data.pop_front();
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(tree_data.front()));
        tree_data.pop_front();
        root->left = dshelper(tree_data);
        root->right = dshelper(tree_data);
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> tree_data;
        string temp;
        for (auto& e : data) {
            if(e == ',') {
                tree_data.push_back(temp);
                temp.clear();
            } else temp.push_back(e);
        }
        if (!temp.empty()) {
            tree_data.push_back(temp);
            temp.clear();
        }
        return dshelper(tree_data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
