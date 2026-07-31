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
public:
    int ans = 1e5;
    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (!node->left && !node->right) {
            ans = min(ans, depth);
            return;
        }
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 1);
        return ans;
    }
};