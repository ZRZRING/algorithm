> 给你一个n个点组成的带边权的有向图，你想要通过改变一些边的方向使其变成有向无环图，求你改变的边中的最大权值，并最小化答案

写了两天了，这个题需要完全理解如何实现的和为什么这么实现，这样真的可以得到进步qwq

如果我们知道最终的答案为$x$，对于大于$x$的答案，我们就多了一些可反转的边的选择（但我们可以不选），必然也是可以得到我们想要的结果的，显然这个满足二分的条件单调性

我们求出答案$x$以后，对于边权大于$x$的边跑一个拓扑求出所有点的拓扑序$dfn$，然后对于边权小于等于$x$的边，设这条边为$(u,v)$，如果$dfn[v]<dfn[u]$，则这条边就要反转

```cpp
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
```