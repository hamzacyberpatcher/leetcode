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
    int getMax(TreeNode* root) {
        if (!root->right) return root->val;
        return getMax(root->right);
    }

    int getMin(TreeNode* root) {
        if (!root->left) return root->val;
        return getMin(root->left);
    }

public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        if (root->left) {
            int maxim = getMax(root->left);
            if (maxim >= root->val) return false;
        }

        if (root->right) {
            int minim = getMin(root->right);
            if (minim <= root->val) return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }
};
