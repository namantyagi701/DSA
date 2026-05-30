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
    void dfs(TreeNode* node, TreeNode* par,
             unordered_map<TreeNode*, TreeNode*> &parent) {
        if (!node)
            return;

        parent[node] = par;
        dfs(node->left, node, parent);
        dfs(node->right, node, parent);
    }
    void bfs(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parent,
             int k, vector<int>& ans) {

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        while (!q.empty()) {

            int size = q.size();

            if (k == 0) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return;
            }

            while (size--) {

                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !vis.count(curr->left)) {
                    vis.insert(curr->left);
                    q.push(curr->left);
                }

                if (curr->right && !vis.count(curr->right)) {
                    vis.insert(curr->right);
                    q.push(curr->right);
                }

                if (parent[curr] && !vis.count(parent[curr])) {
                    vis.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }

            k--;
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<int> ans;
        dfs(root, NULL, parent);
        bfs(target, parent, k, ans);
        return ans;
    }
};