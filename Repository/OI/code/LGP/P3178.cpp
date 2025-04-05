#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int orz=200100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt,dfs_cnt,root;
int tree[1000100],data[orz],p,dis[orz],lazy[1000100];
int size[orz],dep[orz],fa[orz],dfn[orz],son[orz],top[orz];
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
void dfs1(int u,int last){
    size[u]=1;dep[u]=dep[last]+1;fa[u]=last;
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
void build(int now,int l,int r){
    if (l==r){
        tree[now]=data[l];return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    tree[now]=tree[now<<1]+tree[now<<1|1];
}
void lazy_tag(int now,int l,int r,int t){
    tree[now]=tree[now]+(r-l+1)*1ll*t;
    lazy[now]=lazy[now]+t;
}
void pushdown(int now,int l,int r){
    if (!lazy[now])return;
    int mid=(l+r)>>1;
    lazy_tag(now<<1,l,mid,lazy[now]);
    lazy_tag(now<<1|1,mid+1,r,lazy[now]);
    lazy[now]=0;
}
void change(int now,int l,int r,int x,int y,int t){
    if (l>=x&&r<=y){
        lazy_tag(now,l,r,t);return;
    }if (r<x||l>y)return;
    int mid=(l+r)>>1;pushdown(now,l,r);
    if (mid>=x)change(now<<1,l,mid,x,y,t);
    if (mid<y)change(now<<1|1,mid+1,r,x,y,t);
    tree[now]=tree[now<<1]+tree[now<<1|1];
}
int ask(int now,int l,int r,int x,int y){
    if (l>=x&&r<=y)return tree[now];
    int mid=(l+r)>>1;int ans=0;
    pushdown(now,l,r);
    if (mid>=x)ans=ans+ask(now<<1,l,mid,x,y);
    if (mid<y)ans=ans+ask(now<<1|1,mid+1,r,x,y);
    return ans;
}
int chain_ask(int x,int y){
    int tx=top[x],ty=top[y];int ans=0;
    while (tx!=ty){
        if (dep[tx]<dep[ty]){
            swap(x,y);swap(tx,ty);
        }
        ans=ans+ask(1,1,n,dfn[tx],dfn[x]);
        x=fa[tx];tx=top[x];
    }
    if (dep[x]>dep[y])swap(x,y);
    ans=ans+ask(1,1,n,dfn[x],dfn[y]);
    return ans;
}
signed main(){file();
    n=read();m=read();
    for (int i=1;i<=n;i++){
        dis[i]=read();
    }
    for (int i=1;i<=n-1;i++){
    	int u=read(),v=read();
    	add(u,v);add(v,u);
	}
    dfs1(1,0);dfs2(1,0);build(1,1,n);
    for (int i=1;i<=m;i++){
        int t=read();
        if (t==1){
            int x=read();int z=read();
            change(1,1,n,dfn[x],dfn[x],z);
        }
        if (t==2){
            int x=read();int z=read();
            change(1,1,n,dfn[x],dfn[x]+size[x]-1,z);
        }
        if (t==3){
            int x=read();
            printf("%lld\n",chain_ask(1,x));
        }
    }
    return 0;
}
