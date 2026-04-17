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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*, int>> q;
        map<int , int> mpp;
       
        q.push({root , 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            mpp[p.second] = node -> val;

            if(node -> left){
                q.push({node -> left , p.second + 1});
            }
            if(node -> right){
                q.push({node -> right , p.second + 1});
            }
        }
     
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};