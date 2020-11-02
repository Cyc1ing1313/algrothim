#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    
    string kthSmallestPath(vector<int>& destination, int k) {
        int m = destination[0];
        int n = destination[1];
        vector<vector<int>> count(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                count[i][j] = (j+1<n?count[i][j+1]:0) + (i+1<m?count[i+1][j]:0);
            }
        }
        return dfs(m,n,0,0,k,count);

    }

    string dfs(int m,int n,int sm,int sn,int k,vector<vector<int>>& count){
        if(k==)
        if(sm==m&&sn==n) return "";
        if(sm+1>=m){
            return 'H'+dfs(m,n,sm,sn+1,k,count);
        }
        if(sn+1<n){
            return 'V'+dfs(m,n,sm+1,sn,k,count);
        }
        int a = count[sm+1][sn];
        int b = count[sm][sn+1];
        if(k>b){
            return 'V'+dfs(m,n,sm+1,sn,k-b-,count);
        }else{
            return 'H'+dfs(m,n,sm,sn+1,k,count);
        }
    }
};