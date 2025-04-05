#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <bitset>
using namespace std;
const int orz=100100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[2000000],e2[100000];
int head[orz],n,m,cnt,X1,X2,Y1,Y2,dis[4][orz],vis[orz];
int cnt2,dis2[orz],d[orz],ans;
inline int read(){
    int sym(0),res(0);char ch(0);
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
    edge[cnt].pre=u;
    edge[cnt].dis=t;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void add2(int u,int v,int t){
    e2[++cnt2].ver=v;
    e2[cnt2].pre=u;
    e2[cnt2].dis=t;
    e2[cnt2].nxt=head[u];
    head[u]=cnt2;
}
void spfa(int num,int s){
    queue<int>q;
    q.push(s);dis[num][s]=0;vis[s]=1;dis[num][s]=0;
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            if (dis[num][u]+edge[i].dis<dis[num][v]){
                dis[num][v]=dis[num][u]+edge[i].dis;
                if (!vis[v]){vis[v]=1;q.push(v);}
            }
        }
        vis[u]=0;
    }
}
int main(){
    n=read();m=read();X1=read();Y1=read();X2=read();Y2=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),t=read();add(x,y,t);add(y,x,t);
    }memset(dis,0x3f,sizeof(dis));
    spfa(0,X1);spfa(1,Y1);spfa(2,X2);spfa(3,Y2);
    memset(head,0,sizeof(head));

    //round 1

    for (int i=1;i<=cnt;i++){
        int u=edge[i].pre,v=edge[i].ver,t=edge[i].dis;
        if (dis[0][u]+dis[1][v]+t==dis[0][Y1]){
            if (dis[2][u]+dis[3][v]+t==dis[2][Y2]){
                add2(u,v,t);d[v]++;continue;
            }
            add2(u,v,0);d[v]++;
        }
    }
    queue<int>q;
    for (int i=1;i<=n;i++){
        if (!d[i])q.push(i);
    }
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=e2[i].nxt){
            int v=e2[i].ver;
            dis2[v]=max(dis2[v],dis2[u]+e2[i].dis);
            ans=max(ans,dis2[v]);
            if (!--d[v])q.push(v);
        }
    }

    //round 2

    cnt2=0;memset(head,0,sizeof(head));memset(dis2,0,sizeof(dis2));memset(d,0,sizeof(d));
    for (int i=1;i<=cnt;i++){
        int u=edge[i].pre,v=edge[i].ver,t=edge[i].dis;
        if (dis[0][u]+dis[1][v]+t==dis[0][Y1]){
            if (dis[3][u]+dis[2][v]+t==dis[2][Y2]){
                add2(u,v,t);d[v]++;continue;
            }
            add2(u,v,0);d[v]++;
        }
    }
    while (!q.empty())q.pop();
    for (int i=1;i<=n;i++){
        if (!d[i])q.push(i);
    }
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=e2[i].nxt){
            int v=e2[i].ver;
            dis2[v]=max(dis2[v],dis2[u]+e2[i].dis);
            ans=max(ans,dis2[v]);
            if (!--d[v])q.push(v);
        }
    }
    printf("%d",ans);

    return 0;
}