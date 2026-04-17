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
    int findBottomLeftValue(TreeNode* root) {
         vector<vector<int>>level;
         queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>ans;
            for(int i = 0 ; i < size ; i++){
                TreeNode * node = q.front();
                q.pop();
                ans.push_back(node -> val);
                if(node -> left) q.push(node -> left);
                if(node -> right)q.push(node -> right);
            }
            level.push_back(ans);
        }
        int n = level.size();
        return level[n-1][0];
    }
};