#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
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
struct EDGE{
    int ver,pre,nxt;
}edge[N];
int n,m,head[N],cnt,ans;
int fa[N],siz[N],son[N],dis[N],top[N],dep[N];
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].pre=u;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs1(int u,int last){
    fa[u]=last;siz[u]=1;dep[u]=dep[last]+1;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==last)continue;dfs1(v,u);
        siz[u]+=siz[v];if (siz[v]>siz[son[u]])son[u]=v;
    }
}
void dfs2(int u,int front){
    top[u]=front;if (son[u])dfs2(son[u],front);
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa[u]||v==son[u])continue;dfs2(v,v);
    }
}
int lca(int x,int y){
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]])swap(x,y);x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
int dfs(int u){
    int res=dis[u];
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa[u])continue;res+=dfs(v);
    }
    ans=max(ans,res);return res;
}
int main(){
    n=read();m=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();add(x,y);add(y,x);
    }dfs1(1,0);dfs2(1,1);
    for (int i=1;i<=m;i++){
        int x=read(),y=read();int d=lca(x,y);
        dis[x]++;dis[y]++;dis[d]--;dis[fa[d]]--;
    }
    dfs(1);printf("%d",ans);
    return 0;
}