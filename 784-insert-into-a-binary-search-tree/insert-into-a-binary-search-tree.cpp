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
    TreeNode* insertIntoBST(TreeNode* node, int val) {
        if(!node) return new TreeNode(val);
        TreeNode* root = node;
        while(root -> left != NULL || root -> right != NULL){
            if(root -> val > val){
                if(root -> left)
                root = root -> left;
                else{
                    root -> left = new TreeNode(val);
                    return node;
                }
            }
            else{
                if(root -> right)
                root = root -> right;
                else{
                    root -> right = new TreeNode(val);
                    return node;
                }
            }
        }
        if(root -> val > val){
            root -> left = new TreeNode(val);
        }
        else{
            root -> right = new TreeNode(val);
        }
        return node;
    }
};