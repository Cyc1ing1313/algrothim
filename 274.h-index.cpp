/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int res=0;
        for(int i=citations.size()-1;i>=0;i--){
            if(citations[i]<=res) break;
            res++;
        }
        return res;
    }
};
// @lc code=end

