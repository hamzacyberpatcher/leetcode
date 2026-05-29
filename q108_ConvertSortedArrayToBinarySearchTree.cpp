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
    TreeNode* convertToBst(TreeNode* root, int start, int end, vector<int>& nums)
    {
        if (end < start) return nullptr;

        int i = start + (end - start) / 2;
        root = new TreeNode(nums[i]);

        root->left = convertToBst(root->left, start, i - 1, nums);
        root->right = convertToBst(root->right, i + 1, end, nums);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        int start = 0;
        int end = nums.size() - 1;
        root = convertToBst(root, start, end, nums);
        return root;
    }
};
