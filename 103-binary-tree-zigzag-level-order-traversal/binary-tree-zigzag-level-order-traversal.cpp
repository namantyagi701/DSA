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
    void f(TreeNode *node , vector<vector<int>> &ans){
        if(node == NULL) return;
        queue<TreeNode*>q;
        q.push(node);
        bool flag = false;
        while(!q.empty()){
            vector<int>level;
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                auto curr = q.front();
                q.pop();
                level.push_back(curr -> val);
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
            // flag = !flag;
            // ans.push_back(level);
            if(flag){
                reverse(level.begin() , level.end());
            }
            ans.push_back(level);
            flag =!flag;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>ans;
       f(root , ans);
       return ans;
    }
};