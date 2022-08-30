#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int left=0;
        int right=0;
        multiset<int> s;
        int ret=0;
        while(right<n){
            s.insert(nums[right]);
            right++;
            while(*s.rbegin()-*s.begin() > limit){
                s.erase(s.find(nums[left]));
                left++;
            }
            ret = max({ret,right-left});
            
        }
        return ret;
    }
};