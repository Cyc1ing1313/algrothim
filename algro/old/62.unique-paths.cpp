/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) continue;
                dp[i][j] = (i-1>=0?dp[i-1][j]:0)+(j-1>=0?dp[i][j-1]:0);
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

