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
    int count = 0;

    void dfs(TreeNode* node, long long curSum, int target, unordered_map<long long, int> prefixSum) {
        if (!node) return;

        curSum += node->val;
        if (prefixSum.count(curSum - target)) count += prefixSum[curSum - target];
        prefixSum[curSum]++;

        dfs(node->left, curSum, target, prefixSum);
        dfs(node->right, curSum, target, prefixSum);

        prefixSum[curSum]--; // backtrack
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        dfs(root, 0, targetSum, prefixSum);
        return count;
    }
};