/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
#include<vector>
using namespace std;
class NumArray {
public:
    vector<int> c;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        c = vector<int>(arr.size()+1,0);
        for(int i=0;i<nums.size();i++){
            add(i+1,nums[i]);
        }
    }
    
    void update(int i, int val) {
        int change = val-arr[i];
        arr[i] = val;
        add(i+1,change);
    }

    void add(int i,int change){
        for(;i<c.size();i+=i&-i){
            c[i] += change;
        }
    }

    int ask(int x){
        int ans=0;
        for(;x;x -= x&-x){
            ans += c[x];
        }
        return ans;
    }

    int sumRange(int i, int j) {
        return ask(j+1)-ask(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end

