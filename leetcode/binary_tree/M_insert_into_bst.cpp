/*
https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            root = new TreeNode(val);
        else
            insertBST(root, val);
        
        return root;
    }
    
    void insertBST(TreeNode* root, int val)
    {
        if (root->left == nullptr && root->val > val)
            root->left = new TreeNode(val);
        else if (root->right == nullptr && root->val < val)
            root->right = new TreeNode(val);
        else if (root->val > val)
            insertBST(root->left, val);
        else if (root->val < val)
            insertBST(root->right, val);
    }
};
