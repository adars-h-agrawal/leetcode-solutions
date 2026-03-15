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
    int maxLevelSum(TreeNode* root) {
        int maxi = INT_MIN, level = 0, ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size(), temp = 0;
            level++;
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front(); q.pop();
                temp += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (temp > maxi) {
                maxi = temp;
                ans = level;
            }
        }
        return ans;
    }
};