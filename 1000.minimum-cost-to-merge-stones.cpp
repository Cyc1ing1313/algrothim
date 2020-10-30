/*
 * @lc app=leetcode id=1000 lang=cpp
 *
 * [1000] Minimum Cost to Merge Stones
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int dp[31][31];
    int sum[31];
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n-1)%(K-1)!=0) return -1;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            sum[i] = sum[i-1]+stones[i-1];

        }
        for(int len=K;len<=n;len++){
            for(int i=0,j=i+len-1;j<n;i++,j++){
                dp[i][j] = INT_MAX;
                for(int k=i;k<j;k+=(K-1)){
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                if((len-1)%(K-1)==0){
                        dp[i][j] += (sum[j+1]-sum[i]);
                }
            }
        }
        return dp[0][n-1];
    }

};
// @lc code=end

