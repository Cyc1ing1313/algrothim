/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int curr1 = nums[0];
        int curr2 = nums[0];
        int count1 = 0;
        int count2 = 0;
        for(auto num : nums){
            if(curr1==num){
                count1++;continue;
            }
            if(curr2==num){
                count2++;continue;
            }
            if(count1==0){
                curr1 = num;
                count1 = 1;
                continue;
            }
            if(count2==0){
                curr2=num;
                count2= 1;
                continue;
            }
            count1--;
            count2--;
        }
        count1=0;count2=0;
        for(auto num:nums){
            if(curr2==num) count2++;
            if(curr1==num) count1++;
        }
        if(curr2 == curr1) count2 = 0;
        vector<int> ret;
        if(count1>n/3) ret.push_back(curr1);
        if(count2>n/3) ret.push_back(curr2);
        return ret;
    }
};
// @lc code=end

