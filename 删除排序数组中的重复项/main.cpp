#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return n;
        }
        int slow=0;
        int fast=1;
        while(fast<n){
            if(nums[fast]!=nums[slow]){
                nums[slow+1] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};