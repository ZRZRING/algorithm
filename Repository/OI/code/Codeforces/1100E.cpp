#include<iostream>
#include<cmath>
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
#define inf 10000000000000
using namespace std;
int read(){
    int res=0;char ch=0;
    while (!isdigit(ch))ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return res;
}
const int N=1000100;
struct EDGE{
    int ver,nxt,dis,pre;
}edge[N];
int n,m,cnt,head[N],vis[N],d[N],ans[N],dfn[N],dfs_cnt;
void add(int u,int v,int t){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    edge[cnt].dis=t;
    edge[cnt].pre=u;
    head[u]=cnt;
}
queue<int>q;
bool check(int x){
    memset(d,0,sizeof(d));memset(vis,0,sizeof(vis));
    for (int i=1;i<=m;i++)if(edge[i].dis>x)d[edge[i].ver]++;
    for (int i=1;i<=n;i++)if (!d[i])q.push(i);
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            if (edge[i].dis<=x)continue;
            int v=edge[i].ver;d[v]--;if (!d[v])q.push(v);
        }
    }
    for (int i=1;i<=n;i++)if (d[i])return 0;
    return 1;
}
void solute(int x){
    memset(d,0,sizeof(d));memset(vis,0,sizeof(vis));
    for (int i=1;i<=m;i++)if(edge[i].dis>x)d[edge[i].ver]++;
    for (int i=1;i<=n;i++)if (!d[i])q.push(i);
    while (!q.empty()){
        int u=q.front();q.pop();dfn[u]=++dfs_cnt;
        for (int i=head[u];i;i=edge[i].nxt){
            if (edge[i].dis<=x)continue;
            int v=edge[i].ver;d[v]--;if (!d[v])q.push(v);
        }
    }
    for (int i=1;i<=m;i++){
        if (edge[i].dis<=x){
            int u=edge[i].pre,v=edge[i].ver;
            if (dfn[u]>dfn[v])ans[++cnt]=i;
        }
    }
}
signed main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),t=read();add(x,y,t);
    }
    int l=0,r=inf;
    while (l<r){
        int mid=l+r>>1;
        if (check(mid))r=mid;
        else l=mid+1;
    }
    cnt=0;solute(r);
    printf("%lld %lld\n",r,cnt);
    for (int i=1;i<=cnt;i++){
        printf("%lld ",ans[i]);
    }
}