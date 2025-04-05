#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct EDGE{
    int nxt,ver,pre;
}edge[1000100],edge2[1000100];
int head[1000100],head2[1000100],n,m,st,ed;
int cnt,can[1000100],dis[1000100],vis[1000100],no[1000100];
int read(){
    int res=0,sym=0;char ch=getchar();
    while(ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
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
void add2(int u,int v){
    edge2[++cnt].ver=v;
    edge2[cnt].nxt=head2[u];
    edge2[cnt].pre=u;
    head2[u]=cnt;
}
void bfs(){
    queue<int>q;
    q.push(ed);can[ed]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for (int i=head2[u];i;i=edge2[i].nxt){
            int v=edge2[i].ver;
            if (!can[v]){
                can[v]=1;q.push(v);
            }
        }
    }
}
void SPFA(){
    queue<int>q;memset(dis,127,sizeof(dis));
    q.push(st);dis[st]=0;vis[st]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            if (dis[u]+1<dis[v]){
                dis[v]=dis[u]+1;
                if (!vis[v]){
                    q.push(v);vis[v]=1;
                }
            }
        }
        vis[u]=0;
    }
}
int main(){file();
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        add2(y,x);
    }
    st=read();ed=read();
    bfs();
    for (int u=1;u<=n;u++){
        if (!can[u]){
            for (int i=head2[u];i;i=edge2[i].nxt){
                int v=edge2[i].ver;
                if (can[v]){
                    no[v]=1;
                }
            }
        }
    }
    if (!can[st]||no[st]){
        printf("-1");return 0;
    }cnt=0;
    for (int i=1;i<=m;i++){
        int u=edge2[i].pre,v=edge2[i].ver;
        if (can[u]&&can[v]&&!no[u]&&!no[v]){
            add(v,u);
        }
    }
    SPFA();
    printf("%d",dis[ed]);
}