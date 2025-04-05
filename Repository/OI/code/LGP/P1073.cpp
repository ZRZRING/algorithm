#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,nxt;
}edge[1000100];
int n,m,f[1000100],min_dis[1000100],head[1000100],cnt,c[1000100];
int read(){
    int res=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return res;
}
void dfs(int now,int minx,int pre){//minx记录目前走过的点的最小点权
    int flag=1; 
    minx=min(c[now],minx);
    if (min_dis[now]>minx){//min_dis[i]记录起点走到该点的最小点权
        min_dis[now]=minx;flag=0;
    }
    int maxx=max(f[pre],c[now]-minx);//maxx按dp格式计算，即上个阶段和这个阶段
    if (maxx>f[now]){//f[i]记录当前最优解
        f[now]=maxx;flag=0;
    }
    if (flag)return;//保证没有重复解
    for (int i=head[now];i;i=edge[i].nxt){//拓扑dfs
        dfs(edge[i].ver,minx,now);
    }
}
void add(int u,int v){
    edge[++cnt].nxt=head[u];
    edge[cnt].ver=v;
    head[u]=cnt;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int main(){file();
    n=read();m=read();
    for (int i=0;i<1000100;i++)min_dis[i]=1<<30;
    for (int i=1;i<=n;i++)c[i]=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),t=read();
        add(x,y);if (t==2)add(y,x);
    }
    dfs(1,1<<30,0);
    printf("%d\n",f[n]);
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct EDGE{
    int ver,nxt,dis,pre;
}edge[1000100];
int head[1000100],n,m,t,dis[1000100],cnt,vis[1000100];
inline int read(){
    int res=0;char ch=0;
    while (ch<'0'||ch>'9')ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void add(int u,int v,int t){
    edge[++cnt].ver=v;
    edge[cnt].dis=t;
    edge[cnt].pre=u;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void SPFA(){
    queue<int>q;
    q.push(1);memset(dis,127,sizeof(dis));dis[1]=0;vis[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            if (dis[u]+edge[i].dis<dis[v]){
                dis[v]=dis[u]+edge[i].dis;
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
    for (int i=1;i<=n;i++){
        t=read();add(i,i+n,t);add(i+n,i+n+n,-t);
    }
    for (int i=1;i<=m;i++){
        int x=read(),y=read();t=read();
        add(x,y,0);add(x+n,y+n,0);add(x+n+n,y+n+n,0);
        if (t==2){
            add(y,x,0);add(y+n,x+n,0);add(y+n+n,x+n+n,0);
        }
    }m=3*m+2*n;n*=3;
    /*for (int i=1;i<=m;i++){
        cout<<edge[i].pre<<' '<<edge[i].ver<<' '<<edge[i].dis<<endl;
    }*/
    SPFA();
    printf("%d",-dis[n]);
}
*/