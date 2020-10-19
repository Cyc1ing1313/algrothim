/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0;
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(s.count(nums[i]-1)) continue;
            int start = nums[i];
            int len =0;
            while(s.count(start)){
                len++;
                start++;
            }
            res = max({res,len});
        }
        return res;
    }
};
// @lc code=end

