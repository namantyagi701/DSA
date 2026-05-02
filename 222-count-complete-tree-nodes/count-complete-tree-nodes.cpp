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
    int f(TreeNode* root){
        if(root == NULL) return 0;
        
        int lefth = lh(root);
        int righth = rh(root);

        if(lefth == righth) return pow(2 , lefth) -1;

        return 1 + f(root -> left) + f(root -> right);
  
    }

    int rh(TreeNode* root){
        if(root == NULL) return 0;
        int ans = 1 + rh(root -> right);
        return ans;
    }

    int lh(TreeNode* root){
        if(root == NULL) return 0;
        int ans = 1 + lh(root -> left);
        return ans;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) return 1;

        return f(root);
    }
};