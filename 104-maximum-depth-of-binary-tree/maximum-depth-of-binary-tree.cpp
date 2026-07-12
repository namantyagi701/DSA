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
    int maxDepth(TreeNode* root) {
       if(root == nullptr) return 0;
       stack<pair<TreeNode*,int>>st;
       st.push({root , 1});
       int maxi = -1;
       while(!st.empty()){
         auto it = st.top();
         st.pop();
         int h = it.second;
         maxi = max(maxi , h);
         TreeNode* node = it.first;
         if(node -> left){
            st.push({node -> left , h+1});
         }
         if(node -> right){
            st.push({node -> right , h +1 });
         }
       } 
       return maxi;
    }
};