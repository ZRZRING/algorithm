#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int orz=500100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt;
int tree[orz],fa[orz],dep[orz],size[orz],son[orz],dfn[orz];
int dfs_cnt,color[orz],a[orz],top[orz],tag[orz];
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
    fa[u]=last;dep[u]=dep[last]+1;size[u]=1;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==last)continue;
        dfs1(v,u);size[u]+=size[v];
        if (size[v]>size[son[u]])son[u]=v;
    }
}
void dfs2(int u,int front){
    dfn[u]=++dfs_cnt;color[dfn[u]]=a[u];top[u]=front;
    if (son[u])dfs2(son[u],front);
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}
void build(int now,int l,int r){
    if (l==r){
        tree[now]=1;return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    tree[now]=tree[now<<1]+tree[now<<1|1]-(color[mid]==color[mid+1]);
}
void pushdown(int now,int l,int r){
    if (!tag[now]||l==r)return;
    int mid=(l+r)>>1;tree[now<<1]=tree[now<<1|1]=1;
    tag[now<<1]=tag[now<<1|1]=tag[now];
    color[mid]=color[mid+1]=tag[now];
    tag[now]=0;
}
int ask(int now,int l,int r,int x,int y){
    if (l>=x&&r<=y)return tree[now];
    int ans=0,mid=(l+r)>>1;
    pushdown(now,l,r);
    if (mid>=x)ans+=ask(now<<1,l,mid,x,y);
    if (mid+1<=y)ans+=ask(now<<1|1,mid+1,r,x,y);
    if (mid>=x&&mid+1<=y&&color[mid]==color[mid+1])ans--;
    return ans;
}
int chain_ask(int x,int y){
    int tx=x,ty=y,ans=0;
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]])swap(x,y);
        ans+=ask(1,1,n,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if (dep[x]>dep[y])swap(x,y);
    ans+=ask(1,1,n,dfn[x],dfn[y]); 
    while (top[tx]!=top[ty]){
        if (dep[top[tx]]<dep[top[ty]])swap(tx,ty);
        if (color[dfn[top[tx]]]==color[dfn[fa[top[tx]]]])--ans;
        tx=fa[top[tx]];
    }
    return ans;
}
void change(int now,int l,int r,int x,int y,int t){
    if (l>=x&&r<=y){
        tree[now]=1;color[l]=color[r]=tag[now]=t;return;
    }
    int mid=(l+r)>>1;
    pushdown(now,l,r);
    if (mid>=x)change(now<<1,l,mid,x,y,t);
    if (mid+1<=y)change(now<<1|1,mid+1,r,x,y,t);
    tree[now]=tree[now<<1]+tree[now<<1|1]-(color[mid]==color[mid+1]);
}
void chain_change(int x,int y,int t){
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]])swap(x,y);
        change(1,1,n,dfn[top[x]],dfn[x],t);x=fa[top[x]];
    }
    if (dep[x]>dep[y])swap(x,y);
    change(1,1,n,dfn[x],dfn[y],t);
}
int main(){file();
    n=read();m=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
    }
    for (int i=1;i<=n-1;i++){
        int u=read(),v=read();
        add(u,v);add(v,u);
    }
    dfs1(1,0);dfs2(1,0);build(1,1,n);
    char ch;
    for (int i=1;i<=m;i++){
        cin>>ch;
        if (ch=='Q'){
            int x=read(),y=read();
            printf("%d\n",chain_ask(x,y));
        }else{
            int x=read(),y=read(),t=read();
            chain_change(x,y,t);
        }
    }
    return 0;
}
