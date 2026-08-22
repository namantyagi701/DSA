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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return f(i , preorder , INT_MAX);
    }
    TreeNode* f(int &i , vector<int>& arr , int ub){
        if(i == arr.size() || arr[i] > ub) return NULL;

        TreeNode* root = new TreeNode(arr[i++]);

        root -> left = f(i , arr , root -> val);
        root -> right = f(i , arr , ub);

        return root;
    }
};