#include <vector>
using namespace std;
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = (int)nums.size();
        int d1,d0;
        for(int i=1;i<=nums.size();i++){
            int c1 = nums[i-1]+d0;
            int c0 = max(d1,d0);
            d1 = c1;
            d0 = c0;
        }
        return max(d1,d0);
    }
};

