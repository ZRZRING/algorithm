#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct EDGE{
    int ver,nxt;
}edge[100010];
int dfn[100010],low[100010],dfs_cnt,s[100010],top,head[100010],n,m;
int cnt,scc_cnt,color[100010],sum[100010],maxx,res;
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
void tarjan(int u){
    dfn[u]=low[u]=++dfs_cnt;s[top++]=u;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (!dfn[v]){
            tarjan(v);low[u]=min(low[u],low[v]);
        }else if(!color[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (dfn[u]==low[u]){
        scc_cnt++;
        do{
            color[s[--top]]=scc_cnt;
            sum[scc_cnt]++;
        }while (s[top]!=u);
    }
}
int main(){file();
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),tmp=read();
        add(x,y);if (tmp==2)add(y,x);
    }
    for (int i=1;i<=n;i++){
        if (!dfn[i]){
            tarjan(i);
        }
    }
    for (int i=1;i<=n;i++){
        if (sum[color[i]]>maxx){
            maxx=sum[color[i]];res=color[i];
        }
    }
    printf("%d\n",maxx);
    for (int i=1;i<=n;i++){
        if (color[i]==res)printf("%d ",i);
    }
}
