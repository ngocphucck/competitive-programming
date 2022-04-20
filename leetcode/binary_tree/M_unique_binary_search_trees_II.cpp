/*
https://leetcode.com/problems/unique-binary-search-trees-ii/
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
    vector<TreeNode*> createTree(int begin, int end) {
        vector<TreeNode*> res;
        if (begin > end) {
            res.push_back(nullptr);
            return res;
        }
        
        for(int i = begin; i <= end; ++i) {
            vector<TreeNode*> left, right;
            left = createTree(begin, i - 1);
            right = createTree(i+1, end);
            
            for(auto a: left)
                for(auto b : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = a;
                    root->right = b;
                    res.push_back(root);
                }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return createTree(1, n);
    }
};
