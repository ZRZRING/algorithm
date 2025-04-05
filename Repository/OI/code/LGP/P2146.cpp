#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
const int orz=500100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int dep[orz],fa[orz],size[orz],son[orz],dfn[orz],top[orz],dfs_cnt,tag[orz],tree[orz];
int head[orz],n,m,cnt;
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
    size[u]=1;fa[u]=last;dep[u]=dep[last]+1;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==last)continue;
        dfs1(v,u);if (size[v]>size[son[u]])son[u]=v;
        size[u]+=size[v];
    }
}
void dfs2(int u,int front){
    dfn[u]=++dfs_cnt;top[u]=front;
    if (son[u])dfs2(son[u],front);
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (v!=son[u]&&v!=fa[u])dfs2(v,v);
    }
}
void pushup(int now){
    tree[now]=tree[now<<1]+tree[now<<1|1];
}
void lazy(int now,int l,int r,int t){
    tree[now]=t*(r-l+1);tag[now]=t;
}
void pushdown(int now,int l,int r,int mid){
    if (tag[now]==-1)return;
    lazy(now<<1,l,mid,tag[now]);
    lazy(now<<1|1,mid+1,r,tag[now]);
    tag[now]=-1;
}
void change(int now,int l,int r,int x,int y,int t){
    if (x<=l&&r<=y){
        lazy(now,l,r,t);return;
    }
    int mid=l+r>>1;
    pushdown(now,l,r,mid);
    if (mid>=x)change(now<<1,l,mid,x,y,t);
    if (mid+1<=y)change(now<<1|1,mid+1,r,x,y,t);
    pushup(now);
}
void chain_change(int x,int y,int t){
    int res=0;
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]])swap(x,y);
        change(1,1,n,dfn[top[x]],dfn[x],t);
        x=fa[top[x]];
    }
    if (dfn[x]>dfn[y])swap(x,y);
    change(1,1,n,dfn[x],dfn[y],t);
}
int main(){file();
    n=read();memset(tag,-1,sizeof(tag));
    for (int i=2;i<=n;i++){
        int x=read()+1;add(x,i);add(i,x);
    }dfs1(1,0);dfs2(1,0);
    m=read();char s[10];
    for (int i=1;i<=m;i++){
        scanf("%s",s);int tmp=tree[1];
        if (s[0]=='i'){
            int x=read()+1;
            chain_change(1,x,1);
            printf("%d\n",tree[1]-tmp);
        }else{
            int x=read()+1;
            change(1,1,n,dfn[x],dfn[x]+size[x]-1,0);
            printf("%d\n",tmp-tree[1]);
        }
    }
    return 0;
}