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
    bool solve(TreeNode* root, int targetSum, int currSum){
        if(root == NULL){
            return false;
        }
        currSum += root->val;

        if(root->left == NULL && root->right == NULL){
            return targetSum == currSum;
        }
        return solve(root->left, targetSum, currSum) || solve(root->right, targetSum, currSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        bool ans = solve(root, targetSum, currSum);
        return ans;
    }
};