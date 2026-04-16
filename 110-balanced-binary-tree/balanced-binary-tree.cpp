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
    int f(TreeNode* node) {
        if (node == NULL)
            return 0;

        int countL = 1 + f(node->left);
        int countR = 1 + f(node->right);

        return max(countL, countR);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int lh = f(root -> left);
        int rh = f(root -> right);

        if(abs(lh - rh) <= 1 && isBalanced(root -> left) && isBalanced(root -> right)) return true;
        return false;
    }
};