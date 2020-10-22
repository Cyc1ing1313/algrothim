/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> t;
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(0,nums);
        return ret;
    }

    void helper(int len,vector<int>& nums){
        if(len == nums.size()){
            ret.push_back(t);
            return;
        }
        t.push_back(nums[len]);
        helper(len+1,nums);
        t.pop_back();
        helper(len+1,nums);
    }
};
// @lc code=end

