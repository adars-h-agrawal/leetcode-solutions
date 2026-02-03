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
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxi = -10e5, ans = 0, level = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            int cur = 0;
            level++;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front(); q.pop();
                cur += temp->val;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            if (cur > maxi) {
                ans = level;
                maxi = cur;
            }
        }
        return ans;
    }
};