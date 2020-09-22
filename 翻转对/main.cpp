#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        int res = 0;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(floor(nums[i]/2)>nums[j]) res++;
            }
        }
        return res;
    }
};