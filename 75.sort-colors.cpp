/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int i=0;
        while(i<=right){
            while(i<=right && nums[i]==2){
                swap(nums[right--],nums[i]);
            }
            if(nums[i]==0){
                swap(nums[left++],nums[i]);
            }
            i++;
        }
    }
};
// @lc code=end

