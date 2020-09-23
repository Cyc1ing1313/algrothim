#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int ret = nums[0];
        int cmax = nums[0];
        int cmin = nums[0];
        for(int i=1;i<n;i++){
            int temp = cmax;
            cmax = max({nums[i],nums[i]*cmax,nums[i]*cmin});
            cmin = min({nums[i],nums[i]*temp,nums[i]*cmin});
            ret = max({cmax,ret});
        }
        return ret;
    }
};