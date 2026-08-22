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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = root;
        if(!root) return nullptr;
        if(root -> val == key) return helper(root);
        while(node != nullptr){
            if(node -> val > key){
                if(node-> left != nullptr && node -> left -> val == key){
                    node -> left = helper(node -> left);
                    return root;
                }
                else{
                    node = node -> left;
                }
            }
            else{
                if(node-> right != nullptr && node -> right -> val == key){
                    node -> right = helper(node -> right);
                    return root;
                }
                else{
                    node = node -> right;
                }
            }
        }
        return root;
    }
    TreeNode* helper(TreeNode* node){
        if(node -> left == nullptr) return node -> right;
        else if(node -> right == nullptr) return node -> left;
        else{
            TreeNode* rightChild = node -> right;
            TreeNode* lastChild = last(node -> left);
            lastChild -> right = rightChild;
            return node -> left;
        }
        
    }
    TreeNode* last(TreeNode* node){
        if(!node -> right) return node;
        return last(node -> right);
    }
};