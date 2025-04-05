#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
const int orz=600100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt,fa[orz],size[orz],top[orz],dfn[orz];
int son[orz],dep[orz],a[orz],dis[orz],ans[orz],dfs_cnt;
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
    fa[u]=last;size[u]=1;dep[u]=dep[last]+1;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==last)continue;dfs1(v,u);
        if (size[son[u]]<size[v])son[u]=v;size[u]+=size[v];
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
void dfs(int u){
    ans[u]=dis[u];
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa[u])continue;
        dfs(v);ans[u]+=ans[v];
    }
}
int main(){file();
    n=read();
    for (int i=1;i<=n;i++)a[i]=read();
    for (int i=1;i<=n-1;i++){
        int x=read(),y=read();add(x,y);add(y,x);
    }int x=a[1];dfs1(1,0);dfs2(1,1);
    for (int i=2;i<=n;i++){
        int y=a[i],d=lca(x,y);
        dis[x]++;dis[y]++;dis[d]--;dis[fa[d]]--;x=y;
    }
    dfs(1);
    for (int i=2;i<=n;i++)ans[a[i]]--;		
    for (int i=1;i<=n;i++)printf("%d\n",ans[i]);
    return 0;
}