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
    TreeNode* buildTree(TreeNode*& root, vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end)
    {
        if (pre_end < pre_start || in_end < in_start) return nullptr;

        root = new TreeNode(preorder[pre_start]);

        int in_ind = -1;

        for(int i = 0; in_ind == -1 && i < inorder.size(); i++)
            if (inorder[i] == preorder[pre_start]) in_ind = i;

        int leftSize = in_ind - in_start;

        root->left = buildTree(root->left, preorder, inorder, pre_start + 1, pre_start + leftSize, in_start, in_ind - 1);
        root->right = buildTree(root->right, preorder, inorder, pre_start + leftSize + 1, pre_end, in_ind + 1, in_end);

        return root;      
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        buildTree(root, preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        return root;
    }
};
