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
    int height(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(height(root->left), height(root->right));
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        int h = height(root);
        vector<vector<int>> res(h);
        int ind = 0;

        bool r = false;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                res[ind].push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (r) {
                reverse(res[ind].begin(), res[ind].end());
            }

            ind++;
            r = !r;
        }

        return res;
    }
};
