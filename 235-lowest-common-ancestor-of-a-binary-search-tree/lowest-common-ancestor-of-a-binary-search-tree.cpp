/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* f(TreeNode* node , TreeNode* p , TreeNode* q){
        if(!node) return NULL;

        if(node->val > p-> val && node -> val > q-> val){
            return f(node -> left , p , q);
        }
        else if(node->val < p-> val && node -> val < q-> val){
           return  f(node -> right , p , q);
        }
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root , p , q);
    }
};