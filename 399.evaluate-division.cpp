/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int count=0;
        unordered_set<string> s;
        for(auto e:equations){
            if(!s.count(e[0])){
                s.insert(e[0]);
            }
            if(!s.count(e[1])){
                s.insert(e[1]);
            }
        }
        int n = s.size();
        vector<string> nodes(n);
        int tot=0;
        for(auto e:s){
            nodes[tot++] = e;
        }
        vector<vector<int>> dis(count,vector<int>(count,0x3f3f3f3f));
        for(int i=0;i<count;i++){
            for(int j=0;j<count;j++){
                if(i==j) dis[i][j] = 0;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j]=min({dis[i][j],dis[i][k],dis[k][j]});
                }
            }
        }
        


    }
};
// @lc code=end

