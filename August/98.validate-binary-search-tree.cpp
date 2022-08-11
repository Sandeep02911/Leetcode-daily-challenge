/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
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
    bool isValidBST(TreeNode* root, long long min_, long long max_) {
        if(!root) return true;
        
        if(root->val <= min_ || root->val >= max_) return false;
        return isValidBST(root->left, min_, root->val) && isValidBST(root->right, root->val, max_);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};

// other approach
class Solution {
public:
    long long prev;
    Solution() {
        prev = 1LL*INT_MIN-1;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        int ans = isValidBST(root->left);
        if(root->val <= prev) return false;
        prev = root->val;
        ans = ans && isValidBST(root->right);
        return ans;
    }
};
// @lc code=end

