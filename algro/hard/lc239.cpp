#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    deque<int> q;
    void push(int x) {
        while(!q.empty()&&q.back()<x) {
            q.pop_back();
        }
        q.push_back(x);
    }
    void pop(int x) {
        if (!q.empty() && q.front() == x) {
            q.pop_front();
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        q.clear();
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i < k-1) {
                push(nums[i]);
            } else {
                push(nums[i]);
                res.push_back(q.front());
                pop(nums[i-k+1]);
            }
        }
        return res;
    }
};