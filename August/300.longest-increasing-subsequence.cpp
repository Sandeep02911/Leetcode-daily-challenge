/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start

//           top-down dp with memoization       -----------------------------------------------------------
class Solution {
public:
    vector<int> dp;
    Solution() {
        dp.resize(2501, -1);
    }
    
    int max_;
    int helper(vector<int>& nums, int idx) {
        if(idx == nums.size()-1) return 1;
        if(dp[idx] != -1) return dp[idx];

        int ans = 1;
        for(int i = idx+1; i < nums.size(); i++) {
            int rres = helper(nums, i);
            if(nums[i] > nums[idx])
                ans = max(ans, 1 + rres);
        }
        max_ = max(ans, max_);
        return dp[idx] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        max_ = 1;
        helper(nums, 0);
        return max_;
    }
};

//           bottom-up dp        --------------------------------------------------------
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = n-2; i >= 0; --i) {
            for(int j = i+1; j < n; j++) {
                if(nums[j] > nums[i])
                    dp[i] = max(1+dp[j], dp[i]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

