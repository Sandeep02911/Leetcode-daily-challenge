/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start

// recursion with memoisation
class Solution {
public:
    int MOD = 1e9+7;
    int helper(vector<int>& arr, int idx, unordered_map<int, int>& mp) {
        int n = arr.size();
        if(idx == 0) return mp[arr[idx]] = 1;
        if(mp[arr[idx]] != -1) return mp[arr[idx]];
        
        mp[arr[idx]] = 1;
        for(int i = idx-1; i >= 0; --i) {
            int rres = helper(arr, i, mp);
            if(arr[idx] % arr[i] == 0) {
                int left = arr[i];
                int right = arr[idx]/arr[i];
                if(mp.find(right) != mp.end()) {
                    mp[arr[idx]] = (mp[arr[idx]] + (1LL*mp[left]*mp[right]) % MOD) % MOD;
                }
            }
        }
        
        // cout<<arr[idx]<<" "<<mp[arr[idx]]<<endl;
        return mp[arr[idx]];
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;
        sort(arr.begin(), arr.end());

        unordered_map<int, int> mp;
        for(int x: arr) mp[x] = -1;

        helper(arr, n-1, mp); 

        int ans = 0;
        for(auto p: mp) {
            // cout<<p.first<<" "<<p.second<<endl;
            ans = (ans + p.second) % MOD;
        }

        return ans;
    }
};

// bottom up approach
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 1;
        sort(arr.begin(), arr.end());
        int MOD = 1e9+7;
        
        unordered_map<int, int> mp;
        for(int x: arr) mp[x] = 1;
        
        for(int i = 1; i < n; ++i) {
            for(int j = i-1; j >= 0; --j) {
                if(arr[i] % arr[j] == 0 && mp.find(arr[i]/arr[j]) != mp.end()) {
                    mp[arr[i]] = (mp[arr[i]] + (1LL * mp[arr[j]] * mp[arr[i]/arr[j]]) % MOD) % MOD;
                }
            }
        }
        
        int count = 0;
        for(auto p: mp) {
            // cout<<p.first<<" "<<p.second<<endl;
            count = (count + p.second) % MOD;
        }
        
        return count;
    }
};
// @lc code=end

