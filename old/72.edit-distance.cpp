/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m==0||n==0){
            return m==0?n:m;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            dp[i][0] = i;
            for(int j=1;j<=n;j++){
                dp[0][j] = j;
                dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

