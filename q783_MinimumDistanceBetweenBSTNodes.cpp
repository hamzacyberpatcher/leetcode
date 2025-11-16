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
    void inOrderTraverse(TreeNode* root, vector<int>& vals)
    {
        if (!root) return;
        inOrderTraverse(root->left, vals);
        vals.push_back(root->val);
        inOrderTraverse(root->right, vals);
    }

    int minDiffInBST(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        
        vector<int> vals;
        inOrderTraverse(root, vals);

        

        int minDiff = abs(vals[0] - vals[1]);
        
        for(int i = 0; i < vals.size() - 1; i++)
        {
            int currDiff = abs(vals[i] - vals[i + 1]);
            minDiff = min(currDiff, minDiff);
        }

        return minDiff;

    }
};
