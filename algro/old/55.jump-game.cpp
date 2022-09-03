/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_range=0;
        for(int i=0;i<nums.size();i++){
            if(i>max_range)return false;
            max_range = max({max_range,i+nums[i]});
        }
        return true;
    }
};
// @lc code=end

