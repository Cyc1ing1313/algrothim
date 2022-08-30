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
        fa[x] = find(fa[x]);
        return fa[x];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        fa.resize(n);
        for(int i=0;i<n;i++){
            fa[i]=i;
        }
        int ret=n;
        for(auto c : connections){
            int p = find(c[0]),q=find(c[1]);
            if(p!=q){
                fa[p]=fa[q];
                ret -=1;
            }
        }
        return ret-1;
    }
};
// @lc code=end

