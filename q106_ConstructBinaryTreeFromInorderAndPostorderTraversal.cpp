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
    TreeNode* buildTree(TreeNode* root, vector<int>& inorder, vector<int>& postorder, int post_start, int post_end, int in_start, int in_end)
    {
        if (post_end < post_start || in_end < in_start) return nullptr;

        root = new TreeNode(postorder[post_end]);

        int in_ind = -1;

        for(int i = in_start;  i <= in_end; i++)
            if (inorder[i] == postorder[post_end]){ in_ind = i; break;}

        int RSize = in_end - in_ind;

        root->right = buildTree(root->right, inorder, postorder, post_end - RSize, post_end - 1, in_ind + 1, in_end);
        root->left = buildTree(root->left, inorder, postorder, post_start, post_end - RSize - 1, in_start, in_ind - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        root = buildTree(root, inorder, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
        return root;
    }
};
