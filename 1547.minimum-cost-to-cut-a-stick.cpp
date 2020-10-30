/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    
    int minCost(int n, vector<int>& cuts) {
        int dp[110][110];
        memset(dp,0x3f,sizeof(dp));
        cuts.insert(cuts.begin(),0);
        cuts.insert(cuts.end(),n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        // dp[0][0]=0;
        for(int i=1;i<m;i++){
            // dp[i][i]=0;
            dp[i-1][i]=0;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=i+1;j<m;j++){
                for(int k=i+1;k<j;k++){
                    dp[i][j] = min(dp[i][k]+dp[k][j]+cuts[j]-cuts[i],dp[i][j]);
                }
            }
        }
        return dp[0][m-1];
    }
    // int memo[110][110];
    // int minCost(int n, vector<int>& cuts){
    //     memset(memo,-1,sizeof(memo));
    //     cuts.insert(cuts.begin(),0);
    //     cuts.insert(cuts.end(),n);
    //     sort(cuts.begin(),cuts.end());
    //     return helper(cuts,0,cuts.size()-1);
    // }

    // int helper(vector<int>& cuts,int l,int r){
    //     if(memo[l][r]!=-1) return memo[l][r];
    //     if(r-l<=1) {
    //         memo[l][r]=0;
    //         return 0;
    //     }
    //     int ret=INT_MAX;
    //     for(int i=l+1;i<r;i++){
    //         ret=min(ret,helper(cuts,l,i)+helper(cuts,i,r)+cuts[r]-cuts[l]);
    //     }
    //     memo[l][r] = ret;
    //     return ret;
    // }
};
// @lc code=end

