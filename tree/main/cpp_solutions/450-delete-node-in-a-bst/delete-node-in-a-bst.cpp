/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* getMin(TreeNode* node) {
        while (node && node->left) node = node->left;
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // case 1 : node with 0 or 1 child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // case 2 : node with 2 children
            TreeNode* minRight = getMin(root->right);
            root->val = minRight->val;
            root->right = deleteNode(root->right, minRight->val);
        }
        return root;
    }
};