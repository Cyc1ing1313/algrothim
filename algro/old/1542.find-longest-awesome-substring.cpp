/*
 * @lc app=leetcode id=1542 lang=cpp
 *
 * [1542] Find Longest Awesome Substring
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        unordered_map<int,int> map;
        int mask=0;
        int ret=0;
        map[0]=-1;
        for(int i=0;i<n;i++){
            mask ^= (1<<(s[i]-'0'));
            for(int j=0;j<=9;j++){
                if(map.count(mask^(1<<j))){
                    ret = max(ret,i-map[mask^(1<<j)]);
                }
            }
            if(map.count(mask)){
                ret=max(ret,i-map[mask]);
            }else{
                map[mask]=i;
            }
        }
        return ret;

    }
};
// @lc code=end

