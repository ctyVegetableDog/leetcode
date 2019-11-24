//delete node in BST with recursion

TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        else if (root->val > key) root->left = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            else if (!root->left && root->right) return root->right;
            else if (!root->right && root->left) return root->left;
            else {
                TreeNode* p = root->right;
                while(p->left) p = p->left;
                root->val = p->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
