/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> memo;

    int helper(int l,int r){
        if(l >= r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        int min_val = 10000;
        for(int k=l+(r-l)/2;k<=r;k++){
            min_val = min(min_val,max(helper(l,k-1),helper(k+1,r))+k);
        }
        memo[l][r] = min_val;
        return min_val;
    }

    int getMoneyAmount(int n) {
        memo = vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return helper(1,n);
    }


};
// @lc code=end

