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
    void flatten(TreeNode* root) {
       if (!root) return;

       flatten(root->left);

       if (root->left)
       {
        TreeNode* oldR = root->right;

        TreeNode* newInsert = root->left;

        while(newInsert->right) newInsert = newInsert->right;

        newInsert->right = oldR;

        root->right = root->left;

        root->left = nullptr;
       }

       flatten(root->right);
    }
};
