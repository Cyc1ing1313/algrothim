#include<vector>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        if(n==0) return 0;
        int ret = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    if(i-1<0||j-1<0){
                    dp[i][j] = 1;
                    }else{
                        dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    }
                }
                ret += dp[i][j];

            }
        }
        return ret;
    }
};