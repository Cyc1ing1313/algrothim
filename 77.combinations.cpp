/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> t;

    void helper(int n,int c,int k){
        if(c>n && t.size()<k) return;
        if(t.size()==k){
            ret.push_back(t);
            return;
        }
        t.push_back(c);
        helper(n,c+1,k);
        t.pop_back();
        helper(n,c+1,k);
    }
    vector<vector<int>> combine(int n, int k) {
        helper(n,1,k);
        return ret;
    }

    
};
// @lc code=end

