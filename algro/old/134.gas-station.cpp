/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int spare=0;
        int min_spare=INT_MAX;
        int min_index=0;
        for(int i=0;i<gas.size();i++){
            spare +=(gas[i]-cost[i]);
            if(spare < min_spare){
                min_index = i;
                min_spare = spare;
            }
        }
        return spare<0?-1:(min_index+1)%gas.size();
    }
};
// @lc code=end

