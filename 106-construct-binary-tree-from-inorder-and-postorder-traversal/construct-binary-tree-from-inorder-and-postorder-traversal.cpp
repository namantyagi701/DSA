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
    int postIdx;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIdx = n-1;
        for(int i = 0 ; i < n ; i++){
            mpp[inorder[i]] = i;
        }
        return build(postorder , n-1 , 0);
    }

    TreeNode* build(vector<int>& postorder , int end , int start){
        if(start > end) return NULL;
        
        int nodeVal = postorder[postIdx--];
        int idx = mpp[nodeVal];

        TreeNode* node = new TreeNode(nodeVal);

        node -> right = build(postorder , end  , idx + 1);
        node -> left = build(postorder , idx - 1 , start);

        return node;
    }
};