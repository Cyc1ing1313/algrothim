/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int,int> p;
    unordered_map<int,int> size;
    int longestConsecutive(vector<int>& nums){
        int ret=0;
        for(auto num:nums){
            if(p.count(num)) continue;
            p[num] = num;
            size[num] = 1;
            if(p.count(num+1)){
                size[find(num)] += size[find(num+1)];
                p[find(num+1)] = find(num);
            }
            if(p.count(num-1)){
                size[find(num)] += size[find(num-1)];
                p[find(num-1)] = find(num);
            }
            ret=max(ret,size[num]);
        }
        return ret;
    }

    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }

    // int longestConsecutive(vector<int>& nums) {
    //     int res=0;
    //     unordered_set<int> s;
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         s.insert(nums[i]);
    //     }
    //     for(int i=0;i<n;i++){
    //         if(s.count(nums[i]-1)) continue;
    //         int start = nums[i];
    //         int len =0;
    //         while(s.count(start)){
    //             len++;
    //             start++;
    //         }
    //         res = max({res,len});
    //     }
    //     return res;
    // }
};
// @lc code=end

