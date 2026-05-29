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
    void traverseSum(TreeNode* root, int& currSum, int targetSum, bool& isIt)
    {
        if (!root) return;
        
        int sumTillThisNode = currSum + root->val;
        
        if (sumTillThisNode == targetSum && !root->left && !root->right) isIt = true;
        currSum = sumTillThisNode;
        
        traverseSum(root->left, currSum, targetSum, isIt);
        currSum = sumTillThisNode;
        
        traverseSum(root->right, currSum, targetSum, isIt);
        currSum = sumTillThisNode;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        bool isIt = false;
        traverseSum(root, currSum, targetSum, isIt);
        return isIt;
    }
};
