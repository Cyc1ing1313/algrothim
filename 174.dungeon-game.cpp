/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    // int m=0;
    // int n=0;
    // vector<vector<int>> memo;

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT32_MAX));
        dp[m][n-1]=dp[m-1][n]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
    // int calculateMinimumHP(vector<vector<int>>& dungeon) {
    //     m = dungeon.size();
    //     n = dungeon[0].size();
    //     memo = vector(m,vector<int>(n,INT32_MIN));
    //     return helper(dungeon,0,0);
    // }

    // int helper(vector<vector<int>>& dungeon,int i,int j){
    //     if(i==m-1&&j==n-1) return max(1,1-dungeon[i][j]);
    //     if(memo[i][j]!=INT32_MIN) return memo[i][j];
    //     int res;
    //     if(i==m-1){
    //         res = max(1,helper(dungeon,i,j+1)-dungeon[i][j]);
    //     }else if(j==n-1){
    //         res = max(1,helper(dungeon,i+1,j)-dungeon[i][j]); 
    //     }else{
    //         res = max({1,min(helper(dungeon,i,j+1)-dungeon[i][j],helper(dungeon,i+1,j)-dungeon[i][j])});
    //     }
    //     memo[i][j] = res;
    //     return res;        
    // }
};
// @lc code=end

