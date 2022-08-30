#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    
    string kthSmallestPath(vector<int>& destination, int k) {
        int m = destination[0];
        int n = destination[1];
        vector<vector<int>> count(m+n,vector<int>(n,0));
        count[0][0] = 1;
        for(int i=1;i<m+n;i++){
            count[i][0] = 1;
            for(int j=1;j<n&&j<=i;j++){
                count[i][j] = count[i-1][j-1]+count[i-1][j];
            }
        }
        string ret="";
        for(int i=0,max=m+n;i<max;i++){
            if(n>0){
                int o = count[m+n-1][n-1];
                if(k>o){
                    k -= o;
                    ret += "V";
                    --m;
                }else{
                    ret += "H";
                    --n;
                }
            }else{
                ret += "V";
                --m;
            }
        }
        return ret;
    }

    
};