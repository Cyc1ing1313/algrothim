/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
#include<vector> 
#include<queue>
using namespace std;
class Solution {
public:
    int next[6001],head[6001],ver[6001],edge[6001],tot=0;
    void add(int x,int y,int z){
        ver[++tot] = z;
        edge[tot] = y;
        next[tot] = head[x];
        head[x] = tot;
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dis(N+1,0x3f3f3f3f);
        vector<bool> st(N+1,false);
        for(auto time:times){
            add(time[0],time[1],time[2]);
        }
        dis[K] = 0;
        q.push({0,K});
        while(q.size()){
            auto t = q.top();
            int distance = t.first;
            int n = t.second;
            q.pop();
            if(st[n]) continue;
            st[n] = true;
            for(int i=head[n];i;i=next[i]){
                int j = edge[i];
                if(dis[j]>distance+ver[i]){
                    dis[j] = distance+ver[i];
                    q.push({dis[j],j});
                }
            }
        }
        int ret=0;
        for(int i=1;i<=N;i++){
            ret=max(ret,dis[i]);
        }
        if(ret==0x3f3f3f3f) return -1;
        return ret;
    }
};
// @lc code=end

