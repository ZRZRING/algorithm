#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int orz=1000100;
struct hh{
    int l,r,num;
}ask[orz];
int n,tree[orz],a[orz],vis[orz],m,ans[orz];
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
int lowbit(int x){
    return x&(-x);
}
void add(int x,int t){
    while (x<=n){
        tree[x]+=t;x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while (x){
        ans+=tree[x];x-=lowbit(x);
    }return ans;
}
int cmp(hh a,hh b){
    return a.r<b.r;
}
int main(){file();
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
    }m=read();
    for (int i=1;i<=m;i++){
        ask[i].l=read();ask[i].r=read();ask[i].num=i;
    }sort(ask+1,ask+m+1,cmp);
    int next=1;
    for (int i=1;i<=m;i++){
        for (int j=next;j<=ask[i].r;j++){
            if (vis[a[j]]){
                add(vis[a[j]],-1);
            }add(j,1);
            vis[a[j]]=j;
        }
        next=ask[i].r+1;ans[ask[i].num]=sum(ask[i].r)-sum(ask[i].l-1);
    }
    for (int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}