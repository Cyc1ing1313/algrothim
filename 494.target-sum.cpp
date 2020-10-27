/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum=0;
        
        for(auto num : nums){
            sum += num;
        }
        if(abs(sum)<S) return 0;
        vector<vector<int>> dp(n,vector<int>(sum*2+1,0));
        if(nums[0]==0){
            dp[0][sum] = 2;
        }else{
            dp[0][sum+nums[0]] = 1;
            dp[0][sum-nums[0]] =1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<2*sum+1;j++){
                dp[i][j] = (j-nums[i]>=0?dp[i-1][j-nums[i]]:0) + 
                (j+nums[i]<=2*sum?dp[i-1][j+nums[i]]:0);
            }
        }
        return dp[n-1][sum+S];
    }
};
// @lc code=end

