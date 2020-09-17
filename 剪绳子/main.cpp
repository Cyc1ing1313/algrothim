#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1);
        dp[0]=dp[1]=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i] = max({dp[i],dp[i-j]*j,(i-j)*j});
            }
        }
        return dp[n];
    }
};