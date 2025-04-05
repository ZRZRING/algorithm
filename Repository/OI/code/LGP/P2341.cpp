#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,nxt,pre;
}edge[1000100];
int top,cnt,head[1000100],dfn[1000100],low[1000100],s[1000100],scc_cnt;
int color[1000100],n,m,x,y,sum[1000100],rd[1000100],cd[1000100],ans;
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
            sum[scc_cnt]++;
        }while (s[top]!=u);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);add(x,y);
    }cnt=0;
    for (int i=1;i<=n;i++){
        if (!dfn[i]){
            tarjan(i);
        }
    }//cout<<scc_cnt<<endl;
    for (int i=1;i<=m;i++){
        if (color[edge[i].ver]!=color[edge[i].pre]){
            cd[color[edge[i].pre]]++;
        }
    }
    for (int i=1;i<=scc_cnt;i++){
        if (!cd[i]){
            if (ans){ans=0;break;}
            ans=sum[i];
        }
    }
    printf("%d",ans);
}