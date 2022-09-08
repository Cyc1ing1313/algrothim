#include <bits/stdc++.h>

using namespace std;


const int N = 1e4+1;

int a[N];


int find(int x) {
    if(a[x] == x) return x;
    return a[x] = find(a[x]);
}


int main() {
    int m,n,z,x,y;
    cin >> n>>m;
    for(int i=0;i<n;i++) {
        a[i]= i;
    }
    for(int i=0;i<m;i++) {
        cin>>z>>x>>y;
        if(z==1) {
            a[find(x)] = find(y);
        }else {
            if(find(x)==find(y)){
                printf("Y\n");
            }else {
                printf("N\n");
            }
        }
    }
    return 0;
}