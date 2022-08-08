/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long int>> dp(5, vector<long long int>(n, 0));
        int MOD = 1e9+7;
        
        // dp[0][n] stores no. of strings of length n+1 ending with 'a'
        
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < 5; i++) {
                if(j == 0) {
                    dp[i][j] = 1;
                } else if(i == 0) {
                    dp[i][j] = (dp[i+1][j-1] + dp[i+2][j-1] + dp[i+4][j-1]) % MOD;
                } else if(i == 1) {
                    dp[i][j] = (dp[i-1][j-1] + dp[i+1][j-1]) % MOD;
                } else if(i == 2) {
                    dp[i][j] = (dp[i-1][j-1] + dp[i+1][j-1]) % MOD;
                } else if(i == 3) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1]) % MOD;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 5; i++) {
            ans = (ans + dp[i][n-1]) % MOD;
        }
        
        return ans;
    }
};
// @lc code=end

