/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        if(n==0) return;
        for(int j=0;j<n;j++){
            dfs(board,0,j,m,n);
            dfs(board,m-1,j,m,n);
        }
        for(int i=1;i<m-1;i++){
            dfs(board,i,0,m,n);
            dfs(board,i,n-1,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='!'){
                    board[i][j]='O';
                }else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board,int x,int y,int m,int n){
        if(x<0||y<0||x>=m||y>=n||board[x][y]!='O') return;
        if(board[x][y]=='O'){
            board[x][y]='!';
        }
        dfs(board,x+1,y,m,n);
        dfs(board,x,y+1,m,n);
        dfs(board,x-1,y,m,n);
        dfs(board,x,y-1,m,n);
    }
};
// @lc code=end

