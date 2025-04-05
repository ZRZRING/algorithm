#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int orz=500100;
int tree[orz],tmax[orz],a[orz],n,m;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void build(int now,int l,int r){
    if (l==r){
        tree[now]=tmax[now]=a[l];return;
    }
    int mid=(l+r)>>1;
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
    tree[now]=tree[now*2]+tree[now*2+1];
    tmax[now]=max(tmax[now*2],tmax[now*2+1]);
}
void change(int now,int l,int r,int x,int y){
    if (r<x||l>y||tmax[now]<=1)return;
    if (l==r){
        tmax[now]=tree[now]=sqrt(tree[now]);return;
    }
    int mid=(l+r)>>1;
    change(now*2,l,mid,x,y);
    change(now*2+1,mid+1,r,x,y);
    tree[now]=tree[now*2]+tree[now*2+1];
    tmax[now]=max(tmax[now*2],tmax[now*2+1]);
}
int sum(int now,int l,int r,int x,int y){
    if (l>=x&&r<=y)return tree[now];
    if (r<x||l>y)return 0;
    int mid=(l+r)>>1;
    return sum(now*2,l,mid,x,y)+sum(now*2+1,mid+1,r,x,y);
}
signed main(){file();
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
    }
    build(1,1,n);
    m=read();
    for (int i=1;i<=m;i++){
        int k=read(),l=read(),r=read();
        if (l>r)swap(l,r);
        if (k==0){
            change(1,1,n,l,r);
        }else{
            printf("%lld\n",sum(1,1,n,l,r));
        }
    }
    return 0;
}