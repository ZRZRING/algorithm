#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ans(x) (tree[x].ans)
#define pre(x) (tree[x].pre)
#define suf(x) (tree[x].suf)
#define sum(x) (tree[x].sum)
#define ls (now<<1)
#define rs (now<<1|1)
using namespace std;
const int N=500010;
struct TREE{
    int ans,pre,suf,sum;
}tree[N<<2];
int n,m,a[N];
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
int max_3(int a,int b,int c){
    return max(max(a,b),c);
}
void pushup(int now){
    sum(now)=sum(ls)+sum(rs);
    pre(now)=max(pre(ls),sum(ls)+pre(rs));
    suf(now)=max(suf(rs),sum(rs)+suf(ls));
    ans(now)=max_3(ans(ls),ans(rs),suf(ls)+pre(rs));
}
void build(int now,int l,int r){
    if (l==r){
        ans(now)=pre(now)=suf(now)=sum(now)=a[l];return;
    }
    int mid=l+r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(now);
}
TREE query(int now,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[now];
    }
    int mid=l+r>>1;
    if (mid>=y){
        return query(ls,l,mid,x,y);
    }else if (mid+1<=x){
        return query(rs,mid+1,r,x,y);
    }else{
        TREE t,tl=query(ls,l,mid,x,y),tr=query(rs,mid+1,r,x,y);
        t.sum=tl.sum+tr.sum;
        t.pre=max(tl.pre,tl.sum+tr.pre);
        t.suf=max(tr.suf,tr.sum+tl.suf);
        t.ans=max_3(tl.ans,tr.ans,tl.suf+tr.pre);
        return t;
    }
}
void change(int now,int l,int r,int x,int t){
    if (l==x&&r==x){
        ans(now)=pre(now)=suf(now)=sum(now)=t;return;
    }
    int mid=l+r>>1;
    if (mid>=x)change(ls,l,mid,x,t);
    else change(rs,mid+1,r,x,t);
    pushup(now);
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
    }
    build(1,1,n);
    for (int i=1;i<=m;i++){
        int opt=read();
        if (opt==1){
            int x=read(),y=read();if (x>y)swap(x,y);
            printf("%d\n",query(1,1,n,x,y));
        }else{
            int x=read(),t=read();
            change(1,1,n,x,t);
        }
    }
    return 0;
}