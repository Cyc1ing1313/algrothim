
#include<string>
#include<iostream>
using namespace std;
int main(){
    int dp[2][2];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<dp[i][j]<<endl;
        }
    }
    
}