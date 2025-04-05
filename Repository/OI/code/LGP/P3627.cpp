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
    int ver,nxt,pre;
}edge[orz],scc[orz];
queue<int> q;
int head[orz],n,m,cnt,dfn[orz],low[orz],s[orz],top,color[orz],sum[orz],dis[orz];
int dfs_cnt,scc_cnt,scc_s,T,ans[orz],maxx,start,du[orz];
bool p[orz],scc_p[orz];
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
    edge[cnt].pre=u;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void add2(int u,int v){
    scc[++cnt].ver=v;
    scc[cnt].pre=u;
    scc[cnt].nxt=head[u];
    head[u]=cnt;
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
            sum[scc_cnt]+=dis[s[top]];
            if (s[top]==start)scc_s=scc_cnt;
            if (p[s[top]])scc_p[scc_cnt]=1;
        }while (s[top]!=u);
    }
}
int main(){file();
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        add(x,y);
    }
    for (int i=1;i<=n;i++){
        dis[i]=read();
    }
    start=read();T=read();
    for (int i=1;i<=T;i++){
        int tmp=read();p[tmp]=1;
    }
    tarjan(start);
    memset(head,0,sizeof(head));cnt=0;
    for (int i=1;i<=m;i++){
        int u=edge[i].pre,v=edge[i].ver;
        if (color[u]!=color[v]&&dfn[u]&&dfn[v]){
            add2(color[u],color[v]);du[color[v]]++;
        }
    }
    q.push(scc_s);ans[scc_s]=sum[scc_s];
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=scc[i].nxt){
            int v=scc[i].ver;
            ans[v]=max(ans[v],ans[u]+sum[v]);
            if(!(--du[v]))q.push(v);
        }
    }
    for (int i=1;i<=scc_cnt;i++){
        if (scc_p[i]){
            maxx=max(maxx,ans[i]);
        }
    }
    printf("%d",maxx);
    return 0;
}
