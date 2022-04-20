/*
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
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
    vector<int> array1;
    vector<int> array2;
    
    void tree_trav(TreeNode* root, vector<int>& array)
    {
        if (root == nullptr)
            return;
        tree_trav(root->left, array);
        array.push_back(root->val);
        tree_trav(root->right, array);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        tree_trav(root1, array1);
        tree_trav(root2, array2);
        vector<int> res;
        
        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr1 != array1.size() && ptr2 != array2.size())
        {
            if (array1[ptr1] < array2[ptr2])
            {
                res.push_back(array1[ptr1]);
                ptr1++;
            }
            else
            {
                res.push_back(array2[ptr2]);
                ptr2++;
            }
        }
        if (ptr1 != array1.size())
            for(int i = ptr1; i < array1.size(); ++i)
                res.push_back(array1[i]);
        else if (ptr2 != array2.size())
            for(int i = ptr2; i < array2.size(); ++i)
                res.push_back(array2[i]);
        
        return res;
    }
};
