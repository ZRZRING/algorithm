> 给你一张无向连通图和一个起点$s$，求图上到$s$的最短路等于$l$的位置的数量

> 这里"位置"的定义可以在点上，也可以在边上

> $2\leq n\leq 10^5,l\leq 10^9$，保证题目所给的数都是整数

显然我们把每条边拆成$w_i$条长度为$1$的边复杂度是爆炸了的

那对于我们求出了所有点的单源最短路后，我们可以枚举每条边，直接计算该边上有没有点满足条件

可以根据边的两个端点到$s$的最短路求出该边上符合条件的点的数量


```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=500010;
struct EDGE{
    int ver,nxt,dis,pre;
}edge[N];
int n,m,s,head[N],cnt,vis[N],dis[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void add(int u,int v,int t){
    edge[++cnt].ver=v;
    edge[cnt].pre=u;
    edge[cnt].nxt=head[u];
    edge[cnt].dis=t;
    head[u]=cnt;
}
int main(){
    n=read();m=read();s=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),t=read();
        add(x,y,t);add(y,x,t);
    }
    priority_queue<pair<int,int> >q;q.push(mp(0,s));
    memset(dis,0x3f,sizeof(dis));dis[s]=0;
    while (!q.empty()){
        int u=q.top().second;q.pop();
        if (vis[u])continue;vis[u]=1;
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            if (dis[v]>edge[i].dis+dis[u]){
                dis[v]=edge[i].dis+dis[u];
                q.push(mp(-dis[v],v));
            }
        }
    }int ans=0,l=read();
    for (int i=1;i<=n;i++){
        if (dis[i]==l)ans++;
    }
    for (int i=1;i<=cnt;i+=2){
        int u1=edge[i].pre,u2=edge[i].ver;
        int d1=l-dis[u1],d2=l-dis[u2];
        if (d1>0&&d1<edge[i].dis&&dis[u1]+d1<=dis[u2]+edge[i].dis-d1)ans++;
        if (d2>0&&d2<edge[i].dis&&dis[u2]+d2<=dis[u1]+edge[i].dis-d2)ans++;
        if (d1>0&&d2>0&&d1+d2==edge[i].dis)ans--;
    }printf("%d",ans);
    return 0;
}
```