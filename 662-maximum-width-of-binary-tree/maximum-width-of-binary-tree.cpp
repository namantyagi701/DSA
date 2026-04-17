class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});

        unsigned long long ans = 1;

        while(!q.empty()){
            int size = q.size();
            unsigned long long first = q.front().second;
            unsigned long long last = first;

            for(int i = 0 ; i < size ; i++){
                auto p = q.front();
                TreeNode* node = p.first;
                unsigned long long x = p.second;
                q.pop();

                last = x;

                if(node->left)  q.push({node->left, 2*x});
                if(node->right) q.push({node->right, 2*x + 1});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};