/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,10000);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j*j<=i;j++){
                dp[i] = min(dp[i-j*j]+1,dp[i]);
            }
        }
        return dp[n]==INT_MAX?-1:dp[n];
    }
};
// @lc code=end

