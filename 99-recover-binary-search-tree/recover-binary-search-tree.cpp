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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* last;
    TreeNode*middle;

    void f(TreeNode* node){
        if(node == NULL) return;
        f(node -> left);
        
        if(prev-> val > node -> val){
            if(first == NULL){
                first = prev;
                middle = node;
            }
            else{
                last = node;;
            }
        }
        prev = node;
        f(node -> right);
    }
    
    void recoverTree(TreeNode* root) {
        first = last = middle = NULL;
        prev = new TreeNode(INT_MIN);
        f(root);
        if(first && last){
           swap(first -> val , last -> val);
        }
        else if(first && middle){
           swap(first -> val , middle -> val);
        }
    }
};