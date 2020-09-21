#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        vector<int> nums1(nums.begin(),nums.end()--);
        vector<int> nums2(nums.begin()++,nums.end());
        int a = rob_helper(nums1);
        int b = rob_helper(nums2);
        return max({a,b});
    }

    int rob_helper(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int curr,last,prev = 0;
        last = nums[0];
        prev = 0;
        for(int i=2;i<=n;i++){
            curr = max({last,prev+nums[i-1]});
            prev = last;
            last = curr;
        }
        return last;
    }
};