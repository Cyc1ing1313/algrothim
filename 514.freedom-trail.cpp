/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */

// @lc code=start
#include<string>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    multimap<int,int> ring_map;
    vector<vector<int>> memo;
    int findRotateSteps(string ring, string key) {
        for(int i=0;i<ring.size();i++){
            ring_map.insert({ring[i],i});
        }
        memo = vector<vector<int>>(ring.size()+1,vector<int>(key.size()+1,-1));
        return dfs(ring,0,0,key)+key.size();
    }

    int min_dis(int a,int b,int n){
        if(a<b){
            return min(a+n-b,b-a);
        }else{
            return min(b+n-a,a-b);
        }
    }

    int dfs(string ring,int curr,int n,string tar){
        if(memo[curr][n]!=-1) return memo[curr][n];
        if(n == tar.size()) return 0;
        auto beg = ring_map.lower_bound(tar[n]);
        auto end = ring_map.upper_bound(tar[n]);
        int ret = 1000;
        while(beg!=end){
            ret = min(ret,dfs(ring,beg->second,n+1,tar)+min_dis(beg->second,curr,ring.size()));
            beg++;
        }
        memo[curr][n] = ret;
        return ret;
        
    }
};
// @lc code=end

