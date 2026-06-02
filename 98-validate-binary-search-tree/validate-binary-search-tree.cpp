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
    bool f(TreeNode* node , long long mini , long long maxi){
        if(!node) return true;

        bool left = f(node -> left , mini , node -> val);
        bool right = f(node -> right , node ->val , maxi);
        
        return (node -> val > mini && node -> val < maxi) && left && right;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* node = root;
        if(root -> left == NULL && root -> right == NULL) return true;
        return f(node , LLONG_MIN , LLONG_MAX);
    }
};