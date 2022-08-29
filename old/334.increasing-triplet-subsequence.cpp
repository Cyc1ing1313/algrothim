/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int MAX = INT_MAX;
        int small=MAX,mid=MAX;
        for(auto i : nums){
            if(i<=small){
                small = i;
            }else if(i<=mid){
                mid=i;
            }else{
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

