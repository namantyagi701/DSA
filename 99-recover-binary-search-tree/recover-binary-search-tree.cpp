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
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
public:
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root -> left);
        if(prev != NULL && prev -> val > root -> val){
            if(first == nullptr){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root -> right);
    }
    void recoverTree(TreeNode* root) {
        prev = nullptr;
        first = nullptr;
        middle = nullptr;
        last = nullptr;
        inorder(root);
        if(last == NULL){
            swap(middle -> val , first -> val);
        }
        else swap(first -> val , last -> val);
    }
};