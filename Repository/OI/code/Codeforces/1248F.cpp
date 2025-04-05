#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1000010;
struct EDGE{
    int ver,nxt,pre;
}edge[N];
int n,cnt,m,head[N],dfn[N],low[N],scc_cnt,dfs_cnt,scc_sum[N],s[N],top,scc_num[N],d[N];
vector<int>scc[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("in1.txt","r",stdin);
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
            tarjan(v);low[u]=min(low[v],low[u]);
        }else{
            low[u]=min(dfn[v],low[u]);
        }
    }
    if (dfn[u]==low[u]){
        scc_cnt++;
        do{
            scc[scc_cnt].push_back(s[--top]);
            scc_num[s[top]]=scc_cnt;scc_sum[scc_cnt]++;
        }while (s[top]!=u);
    }
}
void init(){
    scc_cnt=0;cnt=0;dfs_cnt=0;
    memset(scc_num,0,sizeof(scc_num));
    memset(scc_sum,0,sizeof(scc_sum));
    memset(head,0,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(d,0,sizeof(d));
}
int main(){//file();
    int T=read();
    while (T--){
        init();
        n=read();m=read();
        for (int i=1;i<=n;i++)scc[i].clear();
        for (int i=1;i<=m;i++){
            int x=read(),y=read();add(x,y);
        }
        for (int i=1;i<=n;i++){
            if (!dfn[i])tarjan(i);
        }
        if (scc_cnt==1){
            printf("No\n");continue;
        }
        for (int i=1;i<=m;i++){
            int u=edge[i].pre,v=edge[i].ver;
            if (scc_num[u]!=scc_num[v]){
                d[scc_num[v]]++;
            }
        }
        int ans=0,c=0;
        for (int i=1;i<=scc_cnt;i++){
            if (d[i]==0){
                ans=scc_sum[i];c=i;break;
            }
        }
        printf("Yes\n%d %d\n",n-ans,ans);
        vector<int>::iterator it;
        for (int j=1;j<=scc_cnt;j++){
            if (j==c)continue;
            for (it=scc[j].begin();it!=scc[j].end();it++){
                int x=(*it);printf("%d ",x);
            }
        }printf("\n");
        for (it=scc[c].begin();it!=scc[c].end();it++){
            int x=(*it);printf("%d ",x);
        }printf("\n");
    }
    return 0;
}