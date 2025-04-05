#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls now<<1
#define rs now<<1|1
using namespace std;
const int N=500010;
int n,m,a[N];
struct TREE{
    double max;int ans;
    #define tmax(i) tree[i].max
    #define tans(i) tree[i].ans
}tree[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int update(int now,int l,int r,double t){
    if (l==r)return tmax(now)>t;
    int mid=l+r>>1;
    if (tmax(ls)<=t)return update(rs,mid+1,r,t);
    else return update(ls,l,mid,t)+tans(now)-tans(ls);
}
void pushup(int now,int l,int r,int mid){
    tmax(now)=max(tmax(ls),tmax(rs));
    tans(now)=tans(ls)+update(rs,mid+1,r,tmax(ls));
}
void change(int now,int l,int r,int x,double t){
    if (l==r){
        tmax(now)=t;tans(now)=1;return;
    }int mid=l+r>>1;
    if (mid>=x)change(ls,l,mid,x,t);
    else change(rs,mid+1,r,x,t);
    pushup(now,l,r,mid);
}
int main(){
    n=read();m=read();
    int x,h;
    for (int i=1;i<=m;i++){
        x=read();h=read();
        change(1,1,n,x,(double)h/(double)x);
        printf("%d\n",tans(1));
    }
    return 0;
}