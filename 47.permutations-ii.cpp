/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ret;
    }

    void dfs(vector<int>& nums,int index){
        if(index==nums.size()){
            ret.push_back(vector<int>(nums));
        }
        unordered_set<int> visit;
        for(int i=index;i<nums.size();i++){
            if(visit.count(nums[i])) continue;
            visit.insert(nums[i]);
            
            swap(nums[index],nums[i]);
            dfs(nums,index+1);
            swap(nums[index],nums[i]);
        }

    }
};
// @lc code=end

