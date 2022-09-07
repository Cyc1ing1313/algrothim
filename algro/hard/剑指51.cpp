#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<int> bits;

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int idx,int v) {
        while(idx<bits.size()){
            bits[idx] += v;
            idx += lowbit(idx);
        }
    }

    int sum(int n) {
        int ret = 0;
        while(n) {
            ret += bits[n];
            n -= lowbit(n);
        }
        return ret;
    }

    int reversePairs(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        bits = vector<int>(n+1,0);
        vector<int> tmp = nums;
        sort(tmp.begin(),tmp.end());
        for(auto &num : nums) {
            num = lower_bound(tmp.begin(),tmp.end(),num) - tmp.begin()+1;
        }
        for(int i=n-1;i>=0;i--){
            res += sum(nums[i]-1);
            update(nums[i],1);

        }
        return res;
    }
};