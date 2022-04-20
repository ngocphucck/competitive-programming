/*
https://leetcode.com/problems/validate-binary-search-tree/
Solution: Backtracking
*/



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
    bool backtracking(TreeNode* node, long long min, long long max) {
        if (node == nullptr)
            return true;
        if (node->val < min || node->val > max)
            return false;
        
        return backtracking(node->left, min, (long long)node->val - 1) && backtracking(node->right, (long long)node->val + 1, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return backtracking(root, INT_MIN, INT_MAX);
    }
};
