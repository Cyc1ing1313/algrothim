#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int superEggDropV1(int K, int N) {
        if(K==1)return N;
        if(K==0)return 0;
        if(N==0)return 0;
        int res =N+1;
        for(int i=1;i<=N;i++){
            res = min({res,max({superEggDropV1(K,i+1),superEggDropV1(K-1,i-1)})+1});
        }
        return res;
    }

    int superEggDropV2(int K, int N) {
        vector<vector<int>> dp(K+1,vector<int>(N+1,0));
        int m = 0;
        while(dp[K][m]<N){
            ++m;
            for(int i=1;i<=K;i++){
                dp[i][m] = dp[i-1][m-1]+dp[i][m-1]+1;
            }
        }
        return m;
    }
};