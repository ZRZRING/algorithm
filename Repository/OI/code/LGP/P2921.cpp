#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <bitset>
using namespace std;
const int orz=500100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt,dfn[orz],low[orz],dfs_cnt,s[orz],top,scc_cnt,color[orz],sum[orz],ans[orz];
inline int read(){
    int sym(0),res(0);char ch(0);
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
        }else if (!color[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (low[u]==dfn[u]){
        scc_cnt++;
        do{
            color[s[--top]]=scc_cnt;
            sum[scc_cnt]++;
        }while (s[top]!=u);
    }
}
void search(int now,int x,int tot){
    if (ans[x]!=0){
        ans[now]=ans[x]+tot;return;
    }
    else search(now,edge[head[x]].ver,tot+1);
}
int main(){
    n=read();
    for (int x=1;x<=n;x++){
        int y=read();
        if (x==y){
            ans[x]=1;continue;
        }
        add(x,y);
    }
    for (int i=1;i<=n;i++){
        if (!dfn[i])tarjan(i);
    }
    for (int i=1;i<=n;i++){
        if (sum[color[i]]!=1){
            ans[i]=sum[color[i]];
        }
    }
    for (int i=1;i<=n;i++){
        if (ans[i]==0){
            search(i,edge[head[i]].ver,1);
        }
    }
    for (int i=1;i<=n;i++)printf("%d\n",ans[i]);
    return 0;
}