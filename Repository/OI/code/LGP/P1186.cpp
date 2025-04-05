#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct EDGE{
    int ver,num,nxt,pre,dis;
}edge[1000100];
int head[1000100],dis[1000100],vis[1000100],pre[1000100],p[1001][1001];
int n,m,cnt,ans;
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
    edge[++cnt].ver=v;edge[cnt].pre=u;
    edge[cnt].dis=t;edge[cnt].num=cnt;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void SPFA(){
    for (int i=1;i<=n;i++){
        dis[i]=1<<30;vis[i]=0;
    }queue<int>q;q.push(1);vis[1]=1;dis[1]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            if (p[u][v]||p[v][u])continue;
            if (dis[u]+edge[i].dis<dis[v]){
                dis[v]=dis[u]+edge[i].dis;
                if (!vis[v]){
                    vis[v]=1;q.push(v);
                }
            }
        }
        vis[u]=0;
    }
}
int main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),t=read();
        add(x,y,t);add(y,x,t);
    }
    for (int i=1;i<=n;i++){
        dis[i]=1<<30;vis[i]=0;
    }queue<int>q;q.push(1);vis[1]=1;dis[1]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            if (dis[u]+edge[i].dis<dis[v]){
                dis[v]=dis[u]+edge[i].dis;pre[v]=u;
                if (!vis[v]){
                    vis[v]=1;q.push(v);
                }
            }
        }
        vis[u]=0;
    }
    ans=dis[n];
    for (int i=n;i>1;i=pre[i]){
        p[i][pre[i]]=1;p[pre[i]][i]=1;
        SPFA();ans=max(dis[n],ans);
        p[i][pre[i]]=0;p[pre[i]][i]=0;
    }printf("%d",ans);
    return 0;
}