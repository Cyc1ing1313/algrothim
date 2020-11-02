// 给你一个整数数组 heights ，表示建筑物的高度。另有一些砖块 bricks 和梯子 ladders 。

// 你从建筑物 0 开始旅程，不断向后面的建筑物移动，期间可能会用到砖块或梯子。

// 当从建筑物 i 移动到建筑物 i+1（下标 从 0 开始 ）时：

// 如果当前建筑物的高度 大于或等于 下一建筑物的高度，则不需要梯子或砖块
// 如果当前建筑的高度 小于 下一个建筑的高度，您可以使用 一架梯子 或 (h[i+1] - h[i]) 个砖块
// 如果以最佳方式使用给定的梯子和砖块，返回你可以到达的最远建筑物的下标（下标 从 0 开始 ）。

// 输入：heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
// 输出：4
// 解释：从建筑物 0 出发，你可以按此方案完成旅程：
// - 不使用砖块或梯子到达建筑物 1 ，因为 4 >= 2
// - 使用 5 个砖块到达建筑物 2 。你必须使用砖块或梯子，因为 2 < 7
// - 不使用砖块或梯子到达建筑物 3 ，因为 7 >= 6
// - 使用唯一的梯子到达建筑物 4 。你必须使用砖块或梯子，因为 6 < 9
// 无法越过建筑物 4 ，因为没有更多砖块或梯子。
// 示例 2：

// 输入：heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
// 输出：7
// 示例 3：

// 输入：heights = [14,3,19,3], bricks = 17, ladders = 0
// 输出：3
#include<vector>
#include<string>
#include<queue>
using namespace std;
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> q;
        int ret=0;
        int consume = 0;
        int i=0;
        for(i=0;i<heights.size()-1;i++){
            int height = heights[i+1]-heights[i];
            if(height>0){
                q.push(height);
                if(q.size()>ladders){
                    consume += q.top();q.pop();
                }
                if(consume>bricks){
                    return i;
                }
            }
        }
        return i;
    }

    // int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    //     int n = heights.size();
    //     int l=0;
    //     int r=n-1;
    //     int res = 0;
    //     while(l<=r){
    //         int mid = (l+r)/2;
    //         if(canReach(heights,bricks,ladders,mid)){
    //             l = mid+1;res=mid;
    //         }else{
    //             r = mid-1;
    //         }
    //     }
    //     return res;
    // }

    // bool canReach(vector<int>& heights, int bricks, int ladders,int target){
    //     if(target==0) return true;
    //     vector<int> distance(target-1,0);
    //     for(int i=0;i<target;i++){
    //         distance[i] = heights[i+1]-heights[i];
    //     }
    //     sort(distance.begin(),distance.end());
    //     for(int i=target-1;i>=0;i--){
    //         if(distance[i]<=0) continue;
    //         if(ladders>0){
    //             ladders--;continue;
    //         }else if(distance[i]<=bricks){
    //             bricks -= distance[i];continue;
    //         }else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // unordered_map<string,int> memo;
    // int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    //     dfs(heights,bricks,ladders,0);
    // }

    // int dfs(vector<int>& heights, int bricks, int ladders,int curr){
    //     string key = to_string(bricks)+'&'+to_string(ladders)+'&'+to_string(curr);
    //     if(memo.count(key)) return memo[key];
    //     if(curr==heights.size()-1){
    //         memo[key] = curr;
    //         return curr;
    //     }
    //     int next = curr+1;
    //     int ret=0;
    //     if(heights[next]<=heights[curr]){
    //             ret = max(ret,dfs(heights,bricks,ladders,curr+1));
    //     }else{
    //         if(heights[next]-heights[curr] <= bricks){
    //             ret = max(ret,dfs(heights,bricks-heights[next]+heights[curr],ladders,curr+1));
    //         }
    //         if(ladders>0){
    //             ret = max(ret,dfs(heights,bricks,ladders-1,curr+1));
    //         }
    //         if(ladders==0 && heights[next]-heights[curr] > bricks){
    //             ret = max(ret,curr);
    //         }
    //     }
    //     memo[key] = ret;
    //     return ret;
    // }
};