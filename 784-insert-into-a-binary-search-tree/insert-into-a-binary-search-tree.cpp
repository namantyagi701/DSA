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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root == NULL) return newNode;
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while(node != NULL){
            if(node-> val > val){
                prev = node;
                node = node -> left;
            }
            else{
                prev = node;
                node = node -> right;
            }
        }
        if(prev -> val > val){
            prev -> left = newNode;
        }
        else{
            prev -> right = newNode;
        }
        return root;
    }
};