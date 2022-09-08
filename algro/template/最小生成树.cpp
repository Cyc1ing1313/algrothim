#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

struct edge {
    int a;
    int b;
    int w;
} edges[N];

int a[N];

int m,n,x,y,z,c;

int find(int x) {
    if (a[x]==x) return x;
    return a[x] = find(a[x]);
}

void add(int x,int y) {
    c--;
    a[x] = y;
}

bool cmp(edge a,edge b) {
    return a.w < b.w;
}

int kruskal() {
    int res = 0;
    int cnt = 0;
    sort(edges,edges+m,cmp);
    for(int i =0;i<m;i++) {
        int x=  find(edges[i].a);
        int y = find(edges[i].b);
        if(x==y) {
            continue;
        }
        res += edges[i].w;
        add(x,y);
        if(++cnt == n-1) {
            return res;
        }
    }
    return res;
}

int main() {
    cin >>n >> m;
    c = n;
    for(int i=0;i<m;i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }
    for(int i=0;i<n;i++) {
        a[i] = i;
    }
    int res= kruskal();
    if(c>1){
        printf("orz");
        return 0;
    }
    printf("%d",res);
}