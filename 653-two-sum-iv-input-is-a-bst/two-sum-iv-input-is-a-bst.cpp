/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTiterator {
private:
    stack<TreeNode*> st;
    bool isReverse;

public:
    BSTiterator(TreeNode* root, bool reverse) {
        isReverse = reverse;
        pushAll(root);
    }
    void pushAll(TreeNode* root) {
        if (isReverse) {
            while (root != nullptr) {
                st.push(root);
                root = root->right;
            }
        } else {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
        }
    }
    int next() {
        TreeNode* curr = st.top();
        st.pop();

        if (isReverse) {
            pushAll(curr->left);
        } else {
            pushAll(curr->right);
        }
        return curr->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator r(root, true);
        BSTiterator l(root, false);

        int right = r.next();
        int left = l.next();
        while (left < right) {

            if (left + right == k)
                return true;
            else if (left + right < k) {
                left = l.next();
            } else
                right = r.next();
        }
        return false;
    }
};