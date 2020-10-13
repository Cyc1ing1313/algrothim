#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ret_index=0;
        int min_tank = 0;
        int tank = 0;
        for(int i=0;i<n;i++){
            if(tank+gas[i]-cost[i]<min_tank){
                ret_index = i;
                min_tank = tank+gas[i]-cost[i];
            }
            tank += gas[i]-cost[i];
        }
        return ret_index;
    }
};