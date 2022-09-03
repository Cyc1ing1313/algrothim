/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<r){
            int mid = l+r>>1;
            if(nums[mid]==target){
                
            }
        }
    }
};
// @lc code=end

