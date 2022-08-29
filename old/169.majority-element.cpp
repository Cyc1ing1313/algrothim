/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr=nums[0];
        int count=0;
        for(auto num:nums){
            if(curr==num){
                count++;
            }else if(--count == 0){
                curr = num;
                count = 1;
            }
        }
        return curr;

    }
};
// @lc code=end

