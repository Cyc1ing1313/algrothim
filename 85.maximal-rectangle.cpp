/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = dp[i-1][]
            }
        }

    }
};
// @lc code=end

