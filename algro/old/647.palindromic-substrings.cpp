/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        bool dp[1001][1001];
        memset(dp,false,sizeof(dp));
        int n = s.size();
        int ret=0;
        for(int len=1;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j =i+len-1;
                dp[i][j] = i+1<=j-1?dp[i+1][j-1]&&s[i]==s[j]:s[i]==s[j];
                if(dp[i][j]){
                    ret++;
                }
            }
        }
        return ret;
    }

    

    
};
// @lc code=end

