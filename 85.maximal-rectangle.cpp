/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        vector<int> nums(n+2,0);
        int ret=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') nums[j+1] +=1;
                if(matrix[i][j]=='0') nums[j+1] = 0;
            }
            ret = max(ret,largestRectangleArea(nums));
        }
        return ret;

    }

    int largestRectangleArea(vector<int>& heights) {
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

