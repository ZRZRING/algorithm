#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define mp(x,y) make_pair(x,y)
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=1010;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
struct EDGE{
    int ver,nxt,dis;
}edge[N];
int n,m,T,w,head[N],cnt,no[N][N],cost[N][N],vis[N],dis[N],dp[N];
void add(int u,int v,int t){
    edge[++cnt]=(EDGE){v,head[u],t};
    head[u]=cnt;
}
priority_queue<pair<int,int> >q;
void dij(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;q.push(mp(0,1));
    while (!q.empty()){
        int u=q.top().second;q.pop();if (vis[u])continue;vis[u]=1;
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;if (vis[v])continue;
            if (dis[u]+edge[i].dis<dis[v]){
                dis[v]=dis[u]+edge[i].dis;q.push(mp(-dis[v],v));
            }
        }
    }
}
int main(){
    T=read();n=read();w=read();m=read();
    for (int i=1;i<=m;i++){
        int u=read(),v=read(),t=read();add(u,v,t);add(v,u,t);
    }
    int D=read();
    for (int i=1;i<=D;i++){
        int x=read(),l=read(),r=read();
        for (int j=l;j<=r;j++)no[x][j]=1;
    }
    for (int l=1;l<=T;l++){
        for (int r=l;r<=T;r++){
            memset(vis,0,sizeof(vis));
            for (int t=l;t<=r;t++){
                for (int i=1;i<=n;i++){
                    if(no[i][t])vis[i]=1;
                }
            }
            dij();cost[l][r]=dis[n];printf("%d\n",dis[n]);
        }
    }
    memset(dp,0x7f,sizeof(dp));
    for (int i=1;i<=T;i++){
        dp[i]=1ll*cost[1][i]*i;
        for (int j=i-1;j>=0;j--){
            dp[i]=min(dp[i],dp[j]+cost[j+1][i]*(i-j)+w);
        }
    }
    printf("%lld",dp[T]);
    return 0;
}