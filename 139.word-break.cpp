/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1,false);
        unordered_set<string> dict;
        for(auto word:wordDict){
            dict.insert(word);
        }
        dp[0] = true;
        for(int i=1;i<=n;i++){
            if(dict.count(s.substr(0,i))) {
                dp[i] = true;
                continue;
            }
            for(int j=1;j<i;j++){
                if(dp[j]){
                    dp[i] = dict.count(s.substr(j,i-j))>0;
                }
                if(dp[i]) break;
            }
        }
        return dp[n];
    }
};
// @lc code=end

