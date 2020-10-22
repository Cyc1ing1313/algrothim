/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> t;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0,candidates,target);
        return ret;
    }

    void dfs(int index,vector<int>& nums,int tar){
        if(tar<0||index>=nums.size()) return;
        if(tar==0){
            ret.push_back(t);
            return;
        }
        dfs(index+1,nums,tar);
        t.push_back(nums[index]);
        dfs(index,nums,tar-nums[index]) ;
        t.pop_back();
    }
};
// @lc code=end

