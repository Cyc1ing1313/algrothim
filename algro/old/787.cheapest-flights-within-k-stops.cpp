/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int ne[5000],ver[5000],edge[5000],head[5000],tot;
    void add(int x,int y,int z){
        ver[++tot] = z;
        edge[tot] = y;
        ne[x] = head[x];
        head[x] = tot;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dis(n,0x3f3f3f3f);
        vector<int> backup(n);
        queue<int> q;
        dis[src]=0;
    }
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    //     vector<int> back(n);vector<int> dis(n,0x3f3f3f3f);
    //     dis[src]=0;
    //     for(int i=0;i<=K;i++){
    //         back.assign(dis.begin(),dis.end());
    //         for(int j=0;j<flights.size();j++){
    //             int x = flights[j][0];
    //             int y = flights[j][1];
    //             int w = flights[j][2];
    //             if(dis[y]>back[x]+w){
    //                 dis[y] = back[x]+w;
    //             }
    //         }
    //     }
    //     if(dis[dst]>0x3f3f3f3f/2) return -1;
    //     return dis[dst];
    // }
    // int ver[5000],edge[5000],next[5000],head[5000],tot=0;
    // int MAX = 0x3f3f3f;
    // int ret = MAX;
    // void add(int x,int y,int z){
    //     ver[++tot] = z;
    //     edge[tot] = y;
    //     next[tot] = head[x];
    //     head[x] = tot;
    // }
    
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    //     memset(ver,0,sizeof(ver));
    //     memset(edge,0,sizeof(edge));
    //     memset(next,0,sizeof(next));
    //     memset(head,0,sizeof(head));
    //     int vis[110];
    //     memset(vis,0,sizeof(vis));
    //     for(auto flight : flights){
    //         add(flight[0],flight[1],flight[2]);
    //     }
    //     dfs(vis,src,K+1,dst,0);
    //     return ret>=MAX?-1:ret;
    // }

    // void dfs(int vis[110],int c,int k,int tar,int w){
    //     if((k==0&&c!=tar )|| w > ret) return;
    //     if(c==tar) {
    //         ret = min(ret,w);
    //         return;
    //     }
    //     for(int i=head[c];i;i=next[i]){
    //         if(!vis[edge[i]]){
    //             vis[edge[i]] = 1;
    //             dfs(vis,edge[i],k-1,tar,w+ver[i]);
    //             vis[edge[i]] = 0;
    //         }
    //     }
    // }
};
// @lc code=end

