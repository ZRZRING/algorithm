#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls son[now][0]
#define rs son[now][1]
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m,rt;
int tag[N],son[N][2],siz[N],fa[N];
bool l_r(int x){
    return x==son[fa[x]][1];
}
void pushup(int now){
    siz[now]=siz[ls]+siz[rs]+1;
}
void pushdown(int now){
    if (!tag[now])return;
    swap(ls,rs);tag[ls]^=1;tag[rs]^=1;tag[now]=0;
}
void build(int last,int l,int r){
    if (l>r)return;int now=l+r>>1;
    son[last][now>last]=now;fa[now]=last;
    build(now,l,now-1);build(now,now+1,r);
    pushup(now);
}
void rotate(int x,int &goal){
    int y=fa[x],z=fa[y],kind=l_r(x);
    if (y==goal)goal=x;else son[z][l_r(y)]=x;
    son[y][kind]=son[x][kind^1];fa[son[x][kind^1]]=y;
    son[x][kind^1]=y;fa[y]=x;fa[x]=z;
    pushup(y);pushup(x);
}
void splay(int x,int &goal){
    for (int y=fa[x];x!=goal;y=fa[x]){
        if (y!=goal)rotate(l_r(x)==l_r(y)?y:x,goal);
        rotate(x,goal);
    }
}
int find(int x){
    int now=rt;
    while (1){
        pushdown(now);
        if (x<=siz[ls])now=ls;
        else{
            x-=siz[ls]+1;
            if (x<=0)return now;
            now=rs;
        }
    }
}
void reverse(int l,int r){
    int x=find(l),y=find(r+2);
    splay(x,rt);splay(y,son[rt][1]);
    tag[son[y][0]]^=1;
}
int main(){
    n=read();m=read();
    rt=n+3>>1;build(0,1,n+2);
    for (int i=1;i<=m;i++){
        int l=read(),r=read();reverse(l,r);
    }
    for (int i=2;i<=n+1;i++)printf("%d ",find(i)-1);
    return 0;
}