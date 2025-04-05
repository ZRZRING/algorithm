#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
using namespace std;
const int orz=500100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt,son[orz],dfs_cnt,dis[orz];
int tmax[orz],tsum[orz],dfn[orz],fa[orz],size[orz],top[orz],data[orz],dep[orz];
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
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
int max(int a,int b){return a>b?a:b;}
void dfs1(int u,int last){
    size[u]=1;fa[u]=last;dep[u]=dep[last]+1;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==last)continue;
        dfs1(v,u);size[u]+=size[v];
        if (size[v]>size[son[u]])son[u]=v;
    }
}
void dfs2(int u,int front){
    dfn[u]=++dfs_cnt;data[dfn[u]]=dis[u];top[u]=front;
    if (son[u])dfs2(son[u],front);
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (v!=fa[u]&&v!=son[u])dfs2(v,v);
    }
}
void pushup(int now){
    tsum[now]=tsum[now<<1]+tsum[now<<1|1];
    tmax[now]=max(tmax[now<<1],tmax[now<<1|1]);
}
void build(int now,int l,int r){
    if (l==r){
        tsum[now]=tmax[now]=data[l];return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
void change(int now,int l,int r,int x,int y,int t){
    if (l==x&&r==y){
        tsum[now]=tmax[now]=t;return;
    }
    int mid=(l+r)>>1;
    if (mid>=x)change(now<<1,l,mid,x,y,t);
    if (mid+1<=y)change(now<<1|1,mid+1,r,x,y,t);
    pushup(now);
}
int ask_max(int now,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tmax[now];
    }
    int mid=(l+r)>>1,res=-(1<<30);
    if (mid>=x)res=max(res,ask_max(now<<1,l,mid,x,y));
    if (mid+1<=y)res=max(res,ask_max(now<<1|1,mid+1,r,x,y));
    return res;
}
int chain_max(int x,int y){
    int res=-(1<<30);
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]])swap(x,y);
        res=max(res,ask_max(1,1,n,dfn[top[x]],dfn[x]));
        x=fa[top[x]];
    }
    if (dep[x]>dep[y])swap(x,y);
    res=max(res,ask_max(1,1,n,dfn[x],dfn[y]));
    return res;
}
int ask_sum(int now,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tsum[now];
    }
    int mid=(l+r)>>1,res=0;
    if (mid>=x)res+=ask_sum(now<<1,l,mid,x,y);
    if (mid+1<=y)res+=ask_sum(now<<1|1,mid+1,r,x,y);
    return res;
}
int chain_sum(int x,int y){
    int res=0;
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]])swap(x,y);
        res+=ask_sum(1,1,n,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if (dep[x]>dep[y])swap(x,y);
    res+=ask_sum(1,1,n,dfn[x],dfn[y]);
    return res;
}
int main(){file();
    n=read();
    for (int i=1;i<=n-1;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    for (int i=1;i<=n;i++){
        dis[i]=read();
    }
    dfs1(1,0);dfs2(1,0);build(1,1,n);
    int q=read();char tmp[10];
    for (int i=1;i<=q;i++){
        scanf("%s",tmp);
        if (tmp[0]=='C'){
            int u=read(),t=read();
            change(1,1,n,dfn[u],dfn[u],t);
        }else
        if (tmp[1]=='M'){
            int x=read(),y=read();
            printf("%d\n",chain_max(x,y));
        }else
        if (tmp[1]=='S'){
            int x=read(),y=read();
            printf("%d\n",chain_sum(x,y));
        }
    }
    return 0;
}