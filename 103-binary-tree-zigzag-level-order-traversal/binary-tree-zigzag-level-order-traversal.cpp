class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        bool flag = false; // false = left→right, true = right→left

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size); // pre-size vector

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // 🔥 key logic
                if (flag)
                    level[size - 1 - i] = curr->val;
                else
                    level[i] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            ans.push_back(level);
            flag = !flag;
        }

        return ans;
    }
};