#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[100010];
int head[100010],n,m,cnt;
int dfn[100010],low[100010],dfs_cnt,scc_cnt,scc_dis[100010],color[100010];
int s[100010],dis[100010],top,d[100010],ans;
bool vis[100010];
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
    edge[cnt].pre=u;
    head[u]=cnt;
}
void bfs(int s){
    queue<int>q;q.push(s);vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;if (vis[v])continue;
            q.push(v);vis[v]=1;
        }
    }
}
void tarjan(int u){
    dfn[u]=low[u]=++dfs_cnt;s[top++]=u;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (!dfn[v]){
            tarjan(v);low[u]=min(low[u],low[v]);
        }else if (!color[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (dfn[u]==low[u]){
        scc_cnt++;
        do{
            color[s[--top]]=scc_cnt;
            if (dis[s[top]])scc_dis[scc_cnt]=min(scc_dis[scc_cnt],dis[s[top]]);
        }while(s[top]!=u);
    }
}
int main(){file();
    n=read();int size=read();
    for (int i=1;i<=size;i++)dis[read()]=read();size=read();
    for (int i=1;i<=size;i++){
        int x=read(),y=read();add(x,y);
    }
    for (int i=1;i<=n;i++)if (dis[i]&&!vis[i])bfs(i);
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            printf("NO\n%d",i);return 0;
        }
    }
    printf("YES\n");memset(scc_dis,127,sizeof(dis));
    for (int i=1;i<=n;i++)if (!dfn[i])tarjan(i);
    for (int i=1;i<=cnt;i++){
        int u=edge[i].pre,v=edge[i].ver;
        if (color[u]!=color[v]){
            d[color[v]]++;
        }
    }
    for (int i=1;i<=scc_cnt;i++){
        if (!d[i])ans+=scc_dis[i];
    }
    printf("%d",ans);

    return 0;
}
/*
1≤p≤n≤3000
1≤r≤8000
1≤dis[i]≤20000
*/