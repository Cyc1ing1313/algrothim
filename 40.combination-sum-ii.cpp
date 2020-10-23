/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> t;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        helper(target,candidates,0);
        return ret;
    }

    void helper(int tar,vector<int>& nums,int index){
        if(index>nums.size() || tar<0) return;
        if(tar==0){
            ret.push_back(t);
            return;
        }
       
        for(int i=index;i<nums.size();i++){
            if(i>index&&nums[i]==nums[i-1]) continue;
            t.push_back(nums[i]);
            helper(tar-nums[i],nums,i+1);
            t.pop_back();
        }
    }
};
// @lc code=end

