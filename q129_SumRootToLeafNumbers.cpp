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
    void totalSum(TreeNode* root, int& curr, int& total)
    {
        if (!root) return;
        
        int numTillThisNode = curr*10 + root->val;
        if (!root->left && !root->right)
        {
            total += numTillThisNode;
            return;
        }

        curr = numTillThisNode;

        totalSum(root->left, curr, total);
        curr = numTillThisNode;
        totalSum(root->right, curr, total);
        curr = numTillThisNode;

    }

    int sumNumbers(TreeNode* root) {
        int curr = 0;
        int total = 0;
        totalSum(root, curr, total);
        return total;
    }
};
