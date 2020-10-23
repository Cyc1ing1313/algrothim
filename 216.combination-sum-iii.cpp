/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> t;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1,n,k);
        return ret;
    }


    void dfs(int index,int n,int k){
        if(k==0 && n==0){
            ret.push_back(t);
            return;
        }
        if(k<0 || index > 9 || n<0) return;
    
        t.push_back(index);
        dfs(index+1,n-index,k-1);
        t.pop_back();
        dfs(index+1,n,k);
    }


};
// @lc code=end

