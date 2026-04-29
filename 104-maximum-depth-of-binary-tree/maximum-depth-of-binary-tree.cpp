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
    int f(TreeNode *root){
        if(root -> left == NULL && root -> right == NULL) return 1;
 
        int l = 0 , r = 0;
        if(root -> left) l = 1 + f(root -> left);
        if(root -> right) r = 1 + f(root -> right);

        return max(l , r);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return NULL;
        return f(root);
    }
};