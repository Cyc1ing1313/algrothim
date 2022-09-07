#include <bits/stdc++.h>

using namespace std;

long long quick_power(long long a,long long b,long long m) {
    long long ans = 1,base = a;
    while(b>0){
        if(b&1) {
            ans *= base;
            ans %= m;
        }
        base *= base;
        base %= m;
        b = b >> 1;
    }
    ans %= m;
    return ans;
}

int main() {
    long long a,b,p;
    cin>>a>>b>>p;
    printf("%d^%d mod %d=%d\n",a,b,p,quick_power(a,b,p));

}