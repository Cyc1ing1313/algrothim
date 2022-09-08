#include <bits/stdc++.h>
using namespace std;

const int N = 5 * 1e6 + 10;
int idx = 0, m, n,s;
int head[N], deepth[N], parent[N][32];
struct node
{
    int v, ne;
} e[N * 2];

void add(int x, int y)
{
    e[idx].v = x;
    e[idx].ne = head[y];
    head[y] = idx++;
}

void dfs(int x,int fa) {
    deepth[x] = deepth[fa]+1;
    parent[x][0] = fa;
    for(int i=1;(i<<1)<=deepth[x];i++){
        parent[x][i] = parent[parent[x][i-1]][i-1];
    }
    for(int i=head[x];i!=-1;i=e[i].ne){
        int v = e[i].v;
        if(v!=fa){
            dfs(v,x);
        }
    }
}

int lca(int x,int y) {
    if(deepth[x]>deepth[y]) return lca(y,x);
    for(int i=20;i>=0;i--){
        if(deepth[x]<=deepth[y]-(1<<i)){
            y = parent[y][i];
        }
    }
    if(x==y) {
        return x;
    }
    for(int i=20;i>=0;i--){
        if(parent[x][i] == parent[y][i]){
            continue;
        }else {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];


}


int main()
{
    cin>>n>>m>>s;
    n--;
    while(n--){
        add()
    }
    while(m--){
        
    }
}