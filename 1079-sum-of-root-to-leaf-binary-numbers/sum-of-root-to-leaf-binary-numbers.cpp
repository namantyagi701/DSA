class Solution {
private:
    void dfs(TreeNode* root, int curr, int &sum) {
        if (!root) return;

        curr = curr * 2 + root->val;

        if (!root->left && !root->right) {
            sum += curr;
            return;
        }

        dfs(root->left, curr, sum);
        dfs(root->right, curr, sum);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};