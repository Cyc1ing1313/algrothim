/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        heights.insert(heights.begin(),0);
        stack<int> st;
        int n = heights.size();
        int ret=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                int hight = heights[st.top()];st.pop();
                int left = st.top();
                ret = max(ret,hight*(i-left-1));
            }
            st.push(i);
        }
        return ret;
    }
};
// @lc code=end

