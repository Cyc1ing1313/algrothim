/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(auto coin : coins){
            for(int i=coin;i<=amount;i++){
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

