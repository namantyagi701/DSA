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
public:
    int maxSum = 0;
    struct NodeInfo {
        int maxi, mini, sum;
        bool isBst;
    };
        NodeInfo dfs(TreeNode* root) {
            if (!root)
                return {INT_MIN, INT_MAX, 0, true};

            auto left = dfs(root->left);
            auto right = dfs(root->right);

            NodeInfo curr;
            if (left.isBst && right.isBst && root->val > left.maxi &&
                root->val < right.mini) {
                    curr.isBst = true;
                    curr.mini = min(root->val, left.mini);
                    curr.maxi = max(root->val , right.maxi);
                    curr.sum = root -> val + left.sum + right.sum;
                    maxSum = max(maxSum , curr.sum);
            }
            else{
                curr.isBst = false;
                curr.mini = INT_MIN;
                curr.maxi = INT_MAX;
                curr.sum = 0;
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