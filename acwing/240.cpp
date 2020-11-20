#include<iostream>
using namespace std;
int fa[200000]; //同类，捕食，被捕食
int n,k;
int get(int x){
    if(x=fa[x]) return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    fa[get(x)] = fa[y];
}

int main(){
    cin>>n>>k;
    int ret=0;
    for(int i=1;i<=3*n;i++){
        fa[i] = i;
    }
    for(int i=1;i<=k;i++){
        int t,x,y;
        cin>>t>>x>>y;
        if(x>n||y>n) ret++;
        else if(k==1){//同类
            if(get(x)==get(y+n) || get(x)=get(y+2n)) ret++;
            else{
                merge(x,y);
                merge(x+n,y+n);
                merge(x+2n,y+2n);
            }
        }else if(k==2){//捕食
            if(x==y||get(x)==get(y)||get(y+n)==get(x)) ret++;
            else{
                merge(x+n,y);
                merge(y+2n,x);
                merge(y,)
            }
        }
    }
    
}