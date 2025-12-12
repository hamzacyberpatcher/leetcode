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
    int getHeight(TreeNode* root)
    {
        if (!root)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};

        int height = getHeight(root);
        vector<double> res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            long long sum = 0;

            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front(); q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back((double) sum / (double) n);

        }

        return res;
    }
};
