/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> t;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used = vector<bool>(nums.size(),false);
        sort(nums.begin(),nums.end());
        helper(0,nums,used);
        return ret;
    }

    void helper(int len,vector<int>& nums,vector<bool>& used){
        if(len == nums.size()){
            ret.push_back(t);
            return;
        }
        helper(len+1,nums,used);
        if(len>0&&nums[len]==nums[len-1]&&!used[len-1]) return;
        t.push_back(nums[len]);
        used[len]=true;
        helper(len+1,nums,used);
        t.pop_back();
        used[len]=false;
        
    }
};
// @lc code=end

