/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
Solution: backtracking
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
    TreeNode* createBalancedTree(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* tree = new TreeNode(nums[mid]);
        tree->left = createBalancedTree(nums, left, mid - 1);
        tree->right = createBalancedTree(nums, mid + 1, right);
        
        return tree;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBalancedTree(nums, 0, nums.size() - 1);
    }
};
