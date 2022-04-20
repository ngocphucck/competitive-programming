/*
https://leetcode.com/problems/binary-search-tree-iterator/
Solution:...
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
class BSTIterator {
public:
    vector<int> order;
    int iter = 0;
    
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        dfs(root->left);
        order.push_back(root->val);
        dfs(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        return order[iter++];
    }
    
    bool hasNext() {
        if (iter == order.size())
            return false;
        
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
