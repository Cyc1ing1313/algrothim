#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return n;
        }
        int slow = 1;
        int fast = 2;
        while(fast<n){
            if(nums[slow-1]!=nums[fast]){
                nums[++slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
};