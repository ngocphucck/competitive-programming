/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    
    void dfs(TreeNode* root, int& numNode, int k, int& ans) {
        if (root == nullptr)
            return;
        dfs(root->left, numNode, k, ans);
        numNode++;
        if (numNode == k) {
            ans = root->val;
            return;
        }
        dfs(root->right, numNode, k, ans);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int numNode = 0;
        dfs(root, numNode, k, ans);
        
        return ans;
    }
};
