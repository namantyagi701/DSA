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
    unordered_map<int,int>mpp;
    int preIdx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0 ; i < n ; i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder , 0 , n-1);
    }
    TreeNode* build(vector<int>&preorder, int start , int end){
        if(start > end) return NULL;

        int nodeVal = preorder[preIdx++];
        TreeNode* node = new TreeNode(nodeVal);

        int idx = mpp[nodeVal];

        node -> left = build(preorder , start , idx -1);
        node -> right = build(preorder , idx+1 , end);

        return node;
    }
};