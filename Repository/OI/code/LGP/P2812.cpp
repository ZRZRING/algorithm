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
int head[orz],n,m,cnt,color[orz],dfn[orz],low[orz],dfs_cnt;
int s[orz],top,scc_cnt,sum[orz],cd[orz],rd[orz],nord,nocd;
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
        ++scc_cnt;
        do{
            color[s[--top]]=scc_cnt;
        }while (s[top]!=u);
    }
}
int main(){file();
    n=read();
    for (int i=1;i<=n;i++){
        int x=read();
        while (x){
            add(i,x);x=read();
        }
    }
    for (int i=1;i<=n;i++){
        if (!dfn[i])tarjan(i);
    }
    if (scc_cnt==1){
        printf("0\n0");
    }
    for (int i=1;i<=cnt;i++){
        int u=edge[i].pre,v=edge[i].ver;
        if (color[u]!=color[v]){
            cd[color[u]]++;rd[color[v]]++;
        }
    }
    for (int i=1;i<=scc_cnt;i++){
        if (!rd[i])nord++;
        if (!cd[i])nocd++;
    }
    printf("%d\n%d",nord,max(nord,nocd));
    return 0;
}