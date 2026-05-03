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
    TreeNode* insertIntoBST(TreeNode* root, int k) {
        TreeNode* node = new TreeNode(k);
        if(!root) return node;
        TreeNode* temp = root;
        TreeNode* floor = new TreeNode(-1);
        while (root) {
            if (root->val < k) {
                floor = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        root = temp;
        if (floor->val == -1) {
            while (root->left) {
                root = root->left;
            }
            root -> left = node;
        }

        if (floor->right) {
            node->right = floor->right;
        }
        floor->right = node;
        return temp;
    }
};