#include <iostream>
#include <algorithm>
using namespace std;
int n = 5;
int v1[] = {1,2,3,4,5};
int v2[] = {1,0,1,0,1};

void solve(){
    sort(v1,v1+n);
    sort(v2,v2+n,greater<int>());
    int ret=0;
    for(int i=0;i<n;i++){
        ret += v1[i]*v2[i];
    }
    cout << ret;
}

int main(){
    solve();
}