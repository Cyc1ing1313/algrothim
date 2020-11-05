/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int,int>> all;
        vector<vector<int>> ret;
        for(auto e:buildings){
            all.insert(make_pair(e[0],-e[2]));
            all.insert(make_pair(e[1],e[2]));
        }
        multiset<int> heights({0});
        vector<int> last = {0,0};
        for(auto e:all){
            if(e.second<0){
                heights.insert(-e.second);
            }else{
                heights.erase(heights.find(e.second));
            }
            auto max_h = *heights.rbegin();
            if(last[1]!=max_h){
                last[0] = e.first;
                last[1] = max_h;
                ret.push_back(last);
            }
        }
        return ret;
    }
};
// @lc code=end

