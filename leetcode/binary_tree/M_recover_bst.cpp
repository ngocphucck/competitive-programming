/*
https://leetcode.com/problems/recover-binary-search-tree/
Solution: dfs
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
    vector<int> order;
    int i = 0;
    
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        dfs(root->left);
        order.push_back(root->val);
        dfs(root->right);
    }
    
    void assign(TreeNode* root) {
        if (root == nullptr)
            return;
        assign(root->left);
        root->val = order[i++];
        assign(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        sort(order.begin(), order.end());
        assign(root);
    }
};
