/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<int> zeros(len,0);
        vector<int> ones(len,0);
        for(int j=0;j<len;j++){
            for(int i=0;i<strs[j].size();i++){
                if(strs[j][i]=='0') zeros[j]++;
                if(strs[j][i]=='1') ones[j]++;
            }
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<len;i++){
            for(int j=m;j>=0;j--){
                for(int k=n;k>=0;k--){
                    if(j-zeros[i]>=0 && k-ones[i]>=0){
                        dp[j][k] = max(dp[j][k],dp[j-zeros[i]][k-ones[i]]+1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

