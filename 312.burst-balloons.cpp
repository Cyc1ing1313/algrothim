/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int dp[501][501];
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        memset(dp,0,sizeof(dp));
        for(int len=1;len<=n+2;len++){
            for(int i=0;i+len-1<=n+1;i++){
                int j = i+len-1;
                for(int k=i+1;k<j;k++){
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+nums[k]*nums[i]*nums[j]);
                }
            }
        }
        return dp[0][n+1];
    }
    // int maxCoins(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> new_nums(n+2);
    //     for(int i=0;i<n;i++){
    //         new_nums[i+1] = nums[i];
    //     }
    //     new_nums[0]=1;
    //     new_nums[n+1]=1;
    //     vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    //     for(int len=1;len<=n;len++){
    //         for(int l=1;l+len-1<=n;l++){
    //             int r = l+len-1;
    //             for(int mid=l;mid<=r;mid++){
    //                 dp[l][r] = max(dp[l][mid-1]+dp[mid+1][r]+new_nums[l-1]*new_nums[r+1]*new_nums[mid],dp[l][r]);
    //             }
    //         }
    //     }
    //     return dp[1][n];
    // }
};
// @lc code=end

