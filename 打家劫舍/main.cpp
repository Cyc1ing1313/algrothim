#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
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