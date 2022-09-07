#include <bits/stdc++.h>

using namespace std;




class Solution {
public:
    vector<bool> a1,a2,col;
    vector<vector<string>> res;
    vector<string> one_res;
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        a1 = vector(2*n,true);
        a2 = vector(2*n,true);
        col = vector(n,true);
        one_res = vector(n,string(n,'.'));
        helper(0,n);
        return res;
    }

    void helper(int x,int n) {
        if(one_res.size()==x) {
            res.push_back(one_res);
            return;
        }

        for(int y=0;y<n;y++){
            if(col[y] && a1[x+y] && a2[x-y+n-1]) {
                one_res[x][y] = 'Q';
                col[y] = a1[x+y] = a2[x-y+n-1] = false;
                helper(x+1,n);
                  col[y] = a1[x+y] = a2[x-y+n-1] = true;
                one_res[x][y] = '.';
            }
        }
    }
};