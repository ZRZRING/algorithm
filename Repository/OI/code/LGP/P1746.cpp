#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int orz=1000100;
struct EDGE{
    int nxt,ver,pre;
}edge[1000100];
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
    dfn[u]=low[u]=++cnt;s[top++]=u;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (dfn[v]){
            low[u]=min(low[u],dfn[v]);
        }else{
            tarjan(v);low[u]=min(low[u],low[v]);
        }
    }
    if (dfn[u]==low[u]){
        scc_cnt++;
        do{
            color[s[--top]]=scc_cnt;
        }while(s[top]!=u);
    }
}
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x=read();
        while (x!=0){
            add(i,x);x=read();
        }
    }cnt=0;
    for (int i=1;i<=n;i++){
        if (!dfn[i])tarjan(i);
    }
    printf("%d\n",scc_cnt);
    for (int i=1;i<=m;i++){
        if (color[edge[i].pre]!=color[edge[i].ver]){
            cd[color[edge[i].pre]]++;
            rd[color[edge[i].ver]]++;
        }
    }
    for (int i=1;i<=scc_cnt;i++){
        ans=max(ans,max(cd[color[i]],rd[color[i]]);
    }
    printf("%d",ans);
}