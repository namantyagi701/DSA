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
    bool isleaf(TreeNode* node){
        if(node -> left == nullptr && node -> right == nullptr) return true;
        return false; 
    }
    bool f(TreeNode* root , int ts , int sum){
        if(isleaf(root)){
            sum += root -> val;
            if(sum == ts){
                return true;
            }
            else return false;
        }
        sum += root -> val;
        
        bool left = false;
        if(root -> left){
            left = f(root -> left , ts ,sum);
        }
        bool right = false;
        if(root -> right){
            right = f(root -> right , ts ,sum);
        }
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return f(root , targetSum , 0);
    }
};