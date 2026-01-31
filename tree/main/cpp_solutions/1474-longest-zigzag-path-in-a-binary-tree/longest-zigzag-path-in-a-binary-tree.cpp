class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, int dir, int len) {
        if (!node) return;

        ans = max(ans, len);

        // dir: 0 = left, 1 = right
        if (dir == 0) {
            dfs(node->right, 1, len + 1);
            dfs(node->left, 0, 1);
        } else {
            dfs(node->left, 0, len + 1);
            dfs(node->right, 1, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root->left, 0, 1);
        dfs(root->right, 1, 1);
        return ans;
    }
};