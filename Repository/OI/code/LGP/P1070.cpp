#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[100010];
int head[100010],n,m,cnt;
int dis[100010],d[100010],HP,l,r;
bool vis[100010];
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
void add(int u,int v,int t){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    edge[cnt].dis=t;
    head[u]=cnt;
}
bool check(int high){
    if(high<d[1]||high<d[n])return 0;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++){
        if (d[i]>high)vis[i]=1;
    }
    priority_queue<pair<int,int> >q;
    memset(dis,0x3f,sizeof(dis));
    q.push(make_pair(0,1));vis[1]=1;dis[1]=0;
    while (!q.empty()){
        int u=q.top().second;q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;if (vis[v])continue;
            if (dis[v]>dis[u]+edge[i].dis){
                dis[v]=dis[u]+edge[i].dis;
                vis[v]=1;q.push(make_pair(-dis[v],v));
            }
        }
    }
    if (dis[n]>HP)return 0;
    else return 1;
}
signed main(){file();
    n=read();m=read();HP=read();l=0x3f3f3f3f3f3f3f3f; 
    for (int i=1;i<=n;i++){
        d[i]=read();l=min(l,d[i]);r=max(r,d[i]);
    }
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),t=read();
        add(x,y,t);add(y,x,t);
    }
    if (!check(r)){
        printf("AFK");return 0;
    }
    while (l<r){
        int mid=(l+r)>>1;
        if (check(mid))r=mid;
        else l=mid+1;
    }
    printf("%lld",r);
    return 0;
}