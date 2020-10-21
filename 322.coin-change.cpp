/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,10000);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=coins.size()-1;j>=0;j--){
                if(i>=coins[j]){
                    dp[i] = min(dp[i-coins[j]]+1,dp[i]);
                }
            }
        }
        return dp[amount]==10000?-1:dp[amount];
    }
};
// @lc code=end

