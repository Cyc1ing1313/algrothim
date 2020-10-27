/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    // unordered_map<string,bool> memo;
    // bool canPartition(vector<int>& nums) {
    //     int sum=0;
    //     for(auto num:nums){
    //         sum += num;
    //     }
    //     if(sum%2 == 1) return false;
    //     return dfs(nums,0,sum/2);
    // }

    // bool dfs(vector<int>& nums,int index,int tar){
    //     string key = to_string(index)+'&'+to_string(tar);
    //     if(memo.count(key)) return memo[key];
    //     if(tar <0 || index >= nums.size()) return false;
    //     if(tar==0) return true;
    //     bool res =  dfs(nums,index+1,tar) || dfs(nums,index+1,tar-nums[index]);
    //     memo[key]=res;
    //     return res;
    // }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto num:nums){
            sum += num;
        }
        if(sum%2==1) return false;
        int half = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(half+1,false));
        if(nums[0]<=half) dp[0][nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=half;j++){
                if(j-nums[i]>=0){
                    dp[i][j] = dp[i-1][j]||dp[i-1][j-nums[i]]||j==nums[i];
                }
            }
        }
        return dp[n-1][half];
    }
};
// @lc code=end

