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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0 ; i < n ; i++){
            mpp[inorder[i]]=i;
        }
        int preIdx = n-1;
        return build(postorder , 0 , n-1 , preIdx);
    }
    TreeNode* build(vector<int>&preorder, int start , int end ,int & preIdx){
        if(start > end) return NULL;

        int nodeVal = preorder[preIdx--];
        TreeNode* node = new TreeNode(nodeVal);

        int idx = mpp[nodeVal];

        node -> right = build(preorder , idx+1 , end, preIdx);
        node -> left = build(preorder , start , idx -1,preIdx);

        return node; 
    }
};