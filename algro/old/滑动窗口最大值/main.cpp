#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        deque<int> q;
        int i=0;
        while(i<n){
            if(!q.empty()&&q.front()<=i-k){
                q.pop_front();
            }
            while(!q.empty()&&nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            i++;
            if(i>=k){
                ret.push_back(q.front());
            }
        }
        return ret;
    }
};