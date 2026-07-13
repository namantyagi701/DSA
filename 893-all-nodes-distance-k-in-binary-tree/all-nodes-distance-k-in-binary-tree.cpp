class Solution {
public:
    void parent(TreeNode* node,
                map<TreeNode*, TreeNode*>& mpp) {
        
        queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();

            if (p->left) {
                mpp[p->left] = p;
                q.push(p->left);
            }

            if (p->right) {
                mpp[p->right] = p;
                q.push(p->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root,
                          TreeNode* target,
                          int k) {
        
        map<TreeNode*, TreeNode*> mpp;
        parent(root, mpp);

        queue<pair<TreeNode*, int>> q;
        map<TreeNode*, bool> vis;

        q.push({target, 0});
        vis[target] = true;

        vector<int> ans;

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (dist == k) {
                ans.push_back(node->val);
                continue;
            }

            if (node->left && !vis[node->left]) {
                vis[node->left] = true;
                q.push({node->left, dist + 1});
            }

            if (node->right && !vis[node->right]) {
                vis[node->right] = true;
                q.push({node->right, dist + 1});
            }

            if (mpp.count(node) && !vis[mpp[node]]) {
                vis[mpp[node]] = true;
                q.push({mpp[node], dist + 1});
            }
        }

        return ans;
    }
};