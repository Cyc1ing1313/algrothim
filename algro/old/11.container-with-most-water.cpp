/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,res=0;
        while(left<right){
            if(height[left]<height[right]){
                res=max({res,height[left]*(right-left)});
                left++;
            }else{
                res=max({res,height[right]*(right-left)});
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

