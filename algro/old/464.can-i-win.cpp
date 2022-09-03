/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger > desiredTotal) return true;
        if((maxChoosableInteger+1)*maxChoosableInteger/2 < desiredTotal) return false;
        int dp[1<<20];
        memset(dp,-1,sizeof(dp));
        return helper(maxChoosableInteger,desiredTotal,dp,0);
    }

    bool helper(int m,int d,int dp[1<<20],int state){
        if(dp[state]!=-1){
            return dp[state];
        }
        for(int i=1;i<=m;i++){
            int temp = (1<<(i-1));
            if((state&temp) == 0){
                if(d-i<=0 || !helper(m,d-i,dp,state|temp)){
                    dp[state] = 1;
                    return 1;
                }
            }
        }
        dp[state] = 0;
        return 0;
    }
};
// @lc code=end

