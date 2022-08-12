/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
        if(!root || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) {
            return root;
        } else if(left) {
            return left;
        } else {
            return right;
        }
    }
};


// Better solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
        if(!root) return root;
        
        if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if(root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};
// @lc code=end

