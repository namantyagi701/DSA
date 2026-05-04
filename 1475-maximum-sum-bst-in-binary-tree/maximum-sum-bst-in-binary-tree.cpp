class Solution {
public:
    int maxSum = 0;

    struct NodeInfo {
        int mini, maxi, sum;
        bool isBST;
    };

    NodeInfo dfs(TreeNode* root) {
        if (!root) return {INT_MAX, INT_MIN, 0, true};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        NodeInfo curr;

     
        if (left.isBST && right.isBST &&
            root->val > left.maxi && root->val < right.mini) {

            curr.isBST = true;
            curr.sum = left.sum + right.sum + root->val;

            curr.mini = min(root->val, left.mini);
            curr.maxi = max(root->val, right.maxi);

            maxSum = max(maxSum, curr.sum);
        } else {

            curr.isBST = false;
            curr.sum = 0;
            curr.mini = INT_MIN;
            curr.maxi = INT_MAX;
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};