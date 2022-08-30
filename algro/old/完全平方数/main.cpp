#include<vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,100000);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            for(int k=1;k*k<=i;k++){
                dp[i] = min({dp[i-k*k]+1,dp[i]});
            }
        }
        return dp[n];
    }
};