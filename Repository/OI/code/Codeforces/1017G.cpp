#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls (now<<1)
#define rs (now<<1|1)
#define tsum(x) (tree[x].sum)
#define tmax(x) (tree[x].max)
using namespace std;
const int N=500010,inf=1e9+7;
struct EDGE{
    int ver,nxt,pre;
}edge[N];
struct node{
    int sum,max;
    node(){
        sum=0;max=-inf;
    }
}tree[N<<2];
int n,m,cnt,head[N],dfs_cnt;
int dfn[N],dep[N],son[N],siz[N],top[N],tag[N],fa[N],rev[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].pre=u;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs1(int u,int last){
    dep[u]=dep[last]+1;siz[u]=1;fa[u]=last;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;dfs1(v,u);
        siz[u]+=siz[v];if (siz[v]>siz[son[u]])son[u]=v;
    }
}
void dfs2(int u,int front){
    dfn[u]=++dfs_cnt;rev[dfn[u]]=u;top[u]=front;
    if (son[u])dfs2(son[u],front);
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (v==son[u])continue;
        dfs2(v,v);
    }
}
node merge(node a,node b){
    node t;
    t.sum=a.sum+b.sum;
    t.max=max(b.max,a.max+b.sum);
    return t;
}
void build(int now,int l,int r){
    if (l==r){
        tsum(now)=tmax(now)=-1;return;
    }int mid=l+r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    tree[now]=merge(tree[ls],tree[rs]);
}
void lazy(int now,int l,int r,int t){
    int len=r-l+1,mid=l+r>>1;
    tmax(now)=t;tsum(now)=len*t;tag[now]=t;
}
void pushdown(int now,int l,int r,int mid){
    if (!tag[now])return;
    lazy(ls,l,mid,tag[now]);
    lazy(rs,mid+1,r,tag[now]);
    tag[now]=0;
}
void add(int now,int l,int r,int x,int t){
    if (l==x&&r==x){
        tsum(now)+=t;tmax(now)+=t;return;
    }int mid=l+r>>1;pushdown(now,l,r,mid);
    if (mid>=x)add(ls,l,mid,x,t);
    else add(rs,mid+1,r,x,t);
    tree[now]=merge(tree[ls],tree[rs]);
}
void change(int now,int l,int r,int x,int y,int t){
    if (x<=l&&r<=y){
        lazy(now,l,r,t);return;
    }int mid=l+r>>1;pushdown(now,l,r,mid);
    if (mid>=x)change(ls,l,mid,x,y,t);
    if (mid+1<=y)change(rs,mid+1,r,x,y,t);
    tree[now]=merge(tree[ls],tree[rs]);
}
node query(int now,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[now];
    }int mid=l+r>>1;pushdown(now,l,r,mid);
    if (mid>=x&&mid+1<=y){
        return merge(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
    }
    if (mid>=x)return query(ls,l,mid,x,y);
    if (mid+1<=y)return query(rs,mid+1,r,x,y);
}
node chain_query(int x){
    node res;
    while (top[x]!=1){
        res=merge(query(1,1,n,dfn[top[x]],dfn[x]),res);
        x=fa[top[x]];
    }res=merge(query(1,1,n,1,dfn[x]),res);return res;
}
void debug(){
    for (int i=1;i<=n;i++){
        printf("%d %d %d\n",i,
        query(1,1,n,dfn[i],dfn[i]).max,
        chain_query(i).max);
    }
}
int main(){
    n=read();m=read();
    for (int i=2;i<=n;i++){
        int x=read();add(x,i);
    }dfs1(1,1);dfs2(1,1);build(1,1,n);
    for (int i=1;i<=m;i++){
        int opt=read(),x=read();
        if (opt==1){
            add(1,1,n,dfn[x],1);
        }if (opt==2){
            change(1,1,n,dfn[x],dfn[x]+siz[x]-1,-1);
            int t=chain_query(x).max;
            add(1,1,n,dfn[x],-t-1);
        }if (opt==3){
            int t=chain_query(x).max;
            if (t>=0)printf("black\n");
            else printf("white\n");
        }
    }
    return 0;
}