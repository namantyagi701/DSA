/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* node,
                unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (curr->left) {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        parent(root, parent_track);
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (dist++ == k)
                break;
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent_track[curr] && !visited[parent_track[curr]]) {
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};