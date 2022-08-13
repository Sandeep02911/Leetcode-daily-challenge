/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size();
        int len = words.size();
        if(n == 0 || len == 0) return ans;

        unordered_map<string, int> mp;
        for(auto word: words) mp[word]++;
        
        int ws = words[0].size();
        for (int i = 0; i < n-len*ws+1; i++) {
            unordered_map<string, int> temp = mp;
            int j = 0;
            for(; j < len; j++) {
                string word = s.substr(i+j*ws, ws);
                if(temp.find(word) == temp.end()) {
                    break;
                } else {
                    temp[word]--;
                    if(temp[word] == 0) temp.erase(word);
                }
            }
            if(j == len) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

