/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return ret;
    }

    void dfs(vector<int>& nums,int index){
        if(index==nums.size()){
            ret.push_back(vector<int>(nums));
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            dfs(nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
};
// @lc code=end

