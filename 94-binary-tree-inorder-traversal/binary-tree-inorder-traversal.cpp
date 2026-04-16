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
    void f(vector<int> &res , TreeNode* node){
        if(node == NULL) return;
        f(res ,node -> left);
        res.push_back(node -> val);
        f(res , node -> right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>res;
       f(res , root);
       return res;
    }
};