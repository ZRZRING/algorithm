#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct EDGE{
    int ver,nxt,pre;
}edge[100010];
int dfn[100010],low[100010],dfs_cnt,s[100010],top,head[100010],n,m;
int cnt,scc_cnt,color[100010],sum[100010],maxx,res,cd[100010],rd[100010],ansA,ansB;
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
        }while (s[top]!=u);
    }
}
int main(){file();
    n=read();
    for (int i=1;i<=n;i++){
        int x=read();
        while(x!=0){
            add(i,x);x=read();
        }
    }
    for (int i=1;i<=n;i++){
        if (!dfn[i]){
            tarjan(i);
        }
    }
    if (scc_cnt==1){
        printf("1\n0");return 0;
    }
    for (int i=1;i<=cnt;i++){
        int u=edge[i].pre,v=edge[i].ver;
        if (color[u]!=color[v]){
            cd[color[u]]++;rd[color[v]]++;
        }
    }
    for (int i=1;i<=scc_cnt;i++){
        if (rd[i]==0)ansA++;if (cd[i]==0)ansB++;
    }
    printf("%d\n%d",ansA,max(ansA,ansB));
}
