/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<string,int> memo;
    bool static cmp(const vector<int>& a,const vector<int>& b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }else{
            return a[0]<b[0];
        }
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
    
        int n = envelopes.size();
        if(n==0||n==1) return n;
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> dp(n,1);
        int res = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][1]>envelopes[j][1]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};
// @lc code=end

