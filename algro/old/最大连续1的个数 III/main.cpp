#include<vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left=0;
        int right=0;
        int zero_count=0;
        int ret=0;
        while(right<A.size()){
            if(A[right]==0){
                zero_count++;
            }
            right++;
            while(zero_count>K){
                if(A[left]==0){
                    zero_count--;
                }
                left++;
            }
            ret = max({ret,right-left});
        }
        return ret;
    }
};