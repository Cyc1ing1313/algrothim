/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> fa;
    int find(int x){
        if(fa[x]=x) return x;
        fa[x] = find(x);
        return fa[x];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        fa.resize(n);
        iota(fa.begin(),fa.end(),0);
        int ret = n;
        for(auto c : connections){
            int p = find(c[0]),q=find(c[1]);
            if(p!=q){
                
            }
        }
    }
};
// @lc code=end

