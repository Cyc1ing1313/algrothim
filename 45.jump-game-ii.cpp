/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0;
        int start=0;
        int end=0;
        while(end<nums.size()-1){
            int t=0;
            for(int i=start;i<=end;i++){
                t = max({nums[i]+i,t});
            }
            res++;
            start = end;
            end = t;
        }
        return res;
    }
};
// @lc code=end

