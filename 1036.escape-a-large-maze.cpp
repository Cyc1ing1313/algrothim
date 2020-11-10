/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    const int N = 1e6;
    int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int x) {
        return x >= 0 && x <= N; 
    }
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        // 坐标离散化
        // 收集坐标
        vector<int> xs{0, N};
        vector<int> ys{0, N};
        for (auto& p : blocked) {
            for (int k = -1; k <= 1; ++k) {
                int x = p[0] + k;
                int y = p[1] + k;
                if (valid(x)) xs.push_back(x);
                if (valid(y)) ys.push_back(y);
            }
        }
        for (int k = -1; k <= 1; ++k) {
            int x = source[0] + k;
            int y = source[1] + k;
            if (valid(x)) xs.push_back(x);
            if (valid(y)) ys.push_back(y);
            x = target[0] + k;
            y = target[1] + k;
            if (valid(x)) xs.push_back(x);
            if (valid(y)) ys.push_back(y);
        }
        // 排序去重
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        int R = xs.size();
        int C = ys.size();
        // 离散化重新构建矩阵
        vector<vector<int> > M(R, vector<int>(C, 0));
        for (auto& p : blocked) {
            int r = lower_bound(xs.begin(), xs.end(), p[0]) - xs.begin();
            int c = lower_bound(ys.begin(), ys.end(), p[1]) - ys.begin();
            M[r][c] = -1;
        }
        int sr = lower_bound(xs.begin(), xs.end(), source[0]) - xs.begin();
        int sc = lower_bound(ys.begin(), ys.end(), source[1]) - ys.begin();
        M[sr][sc] = 1;
        int tr = lower_bound(xs.begin(), xs.end(), target[0]) - xs.begin();
        int tc = lower_bound(ys.begin(), ys.end(), target[1]) - ys.begin();
        M[tr][tc] = 2;
        // 广度优先搜索进行求解
        queue<pair<int, int> > q;
        q.push({sr, sc});
        M[sr][sc] = -1;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for (int i = 0; i < 4; ++i) {
                int r = x + dirs[i][0];
                int c = y + dirs[i][1];
                if (valid(r, c, R, C) && M[r][c] != -1) {
                    if (M[r][c] == 2) return true;
                    q.push({r, c});
                    M[r][c] = -1;
                }
            }
        }
        return false;
    }

    // const int N = 1e6;
    // int dirs[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    // bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    //     vector<int> xs{0,N};
    //     vector<int> ys{0,N};
    //     for(auto e:blocked){
    //         for(int k=-1;k<=1;k++){
    //             int x = e[0]+k;
    //             int y = e[1]+k;
    //             if(x>=0&&x<=N) xs.push_back(x);
    //             if(y>=0&&y<=N) ys.push_back(y);
    //         }
    //     }
    //     for(int k=-1;k<=1;k++){
    //         int x = source[0]+k;
    //         int y = source[1]+k;
    //         if(x>=0&&x<=N) xs.push_back(x);
    //         if(y>=0&&y<=N) ys.push_back(y);
    //         x = target[0]+k;
    //         y = target[1]+k;
    //         if(x>=0&&x<=N) xs.push_back(x);
    //         if(y>=0&&y<=N) ys.push_back(y);
    //     }
    //     sort(xs.begin(),xs.end());
    //     sort(ys.begin(),ys.end());
    //     xs.erase(unique(xs.begin(),xs.end()),xs.end());
    //     ys.erase(unique(ys.begin(),ys.end()),ys.end());
    //     int R = xs.size();
    //     int C = ys.size();
    //     vector<vector<int>> M(R,vector<int>(C,0));
    //     for(auto e:blocked){
    //         int x = lower_bound(xs.begin(),xs.end(),e[0])-xs.begin();
    //         int y = lower_bound(ys.begin(),ys.end(),e[1])-ys.begin();
    //         M[x][y]=-1;
    //     }
    //     int sx = lower_bound(xs.begin(),xs.end(),source[0])-xs.begin();
    //     int sy = lower_bound(ys.begin(),ys.end(),source[1])-ys.begin();
    //     M[sx][sy] = 1;
    //     int ex = lower_bound(xs.begin(),xs.end(),target[0])-xs.begin();
    //     int ey = lower_bound(ys.begin(),ys.end(),target[1])-ys.begin();
    //     M[ex][ey] = 2;
    //     queue<pair<int,int>> q;
    //     q.push({sx,sy});
    //     M[sx][sy]=-1;
    //     while(!q.empty()){
    //         auto curr = q.front();q.pop();
    //         int x = curr.first;
    //         int y = curr.second;
    //         for(int i=0;i<4;i++){
    //             int nx = x+dirs[i][0];
    //             int ny = y+dirs[i][1];
    //             if(nx>=0&&nx<R&&ny>=0&&ny<C && M[nx][ny]!=-1){
    //                 if(M[nx][ny]==2) return true;
    //                 M[nx][ny]=-1;
    //                 q.push({nx,ny});
    //             }
    //         }
    //     }
    //     return false;

    // }
};
// @lc code=end

