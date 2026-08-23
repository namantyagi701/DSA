/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int maxSum = 0;

public:
    struct Nodeinfo {
        int sum, maxi, mini;
        bool isBst;
    };
    Nodeinfo dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, INT_MIN, INT_MAX, true};

        auto left = dfs(root->left);
        auto right = dfs(root->right);
        Nodeinfo curr;
        if (left.isBst && right.isBst && left.maxi < root->val &&
            right.mini > root->val) {
            curr.sum = root -> val + left.sum + right.sum;
            curr.maxi = max(right.maxi, root->val);
            curr.mini = min(left.mini, root->val);
            curr.isBst = true;
            maxSum = max(maxSum, curr.sum);
        } else {
            curr.sum = 0;
            curr.maxi = INT_MAX;
            curr.mini = INT_MIN;
            curr.isBst = false;
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root);
        return maxSum;
    }
};