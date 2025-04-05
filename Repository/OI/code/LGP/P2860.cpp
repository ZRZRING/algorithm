#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[1000100];
int head[1000100],n,m,cnt;
int dfn[1000100],low[1000100],dfs_cnt,s[1000100],top,scc_cnt,color[1000100];
int d[1000100],ans;
bool pd[5001][5001];
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
void tarjan(int u,int last){
    dfn[u]=low[u]=++dfs_cnt;s[top++]=u;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==last)continue;
        if (!dfn[v]){
            tarjan(v,u);low[u]=min(low[u],low[v]);
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (low[u]==dfn[u]){
        scc_cnt++;
        do{
            color[s[--top]]=scc_cnt;
        }while(s[top]!=u);
    }
}
int main(){file();
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        if (pd[x][y])continue;
        pd[x][y]=1;pd[y][x]=1;
        add(x,y);add(y,x);
    }
    for (int i=1;i<=n;i++){
        if (!dfn[i]){
            tarjan(i,0);
        }
    }
    for (int i=1;i<=cnt;i+=2){
        int u=edge[i].pre,v=edge[i].ver;
        if (color[u]!=color[v]){
            d[color[u]]++;d[color[v]]++;
        }
    }
    for (int i=1;i<=scc_cnt;i++){
        if (d[i]==1)ans++;
    }
    printf("%d",(ans+1)/2);
    return 0;
}