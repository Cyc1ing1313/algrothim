/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int res=0;
        s.push(0);
        for(int i=1;i<height.size();i++){
            while(!s.empty()&&height[i]>height[s.top()]){
                int mid_h = height[s.top()];s.pop();
                if(s.empty())break;
                int left_h = height[s.top()];
                int right_h = height[i];
                int dis = i-s.top()-1;
                int height = min({left_h,right_h});
                res += dis*(height-mid_h);
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end

