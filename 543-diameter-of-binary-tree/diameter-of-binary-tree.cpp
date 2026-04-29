class Solution {
public:
    int maxi = 0;

    int height(TreeNode* root) {
        if (!root) return 0;

        int l = height(root->left);
        int r = height(root->right);

        // update diameter
        maxi = max(maxi, l + r);

       return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxi;
    }
};