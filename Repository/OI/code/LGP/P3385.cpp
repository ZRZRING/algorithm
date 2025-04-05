#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct EDGE{
    int ver,nxt,dis;
}edge[1000100];
int cnt,head[1000100],tot[1000100],T,n,m,dis[1000100],x,y,t,vis[1000100];
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int read(){
    int sum=0,sym=0;char ch=getchar();
    while (ch<'0'||ch>'9')sym|=ch=='-',ch=getchar();
    while (ch>='0'&&ch<='9')sum=(sum<<3)+(sum<<1)+(ch^48),ch=getchar();
    return sym?-sum:sum;
}
void add(int u,int v,int dis){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    edge[cnt].dis=dis;
    head[u]=cnt;
}
bool spfa(){
	queue<int>q;
    q.push(1);vis[1]=1;dis[1]=0;
    while (!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            if (dis[u]+edge[i].dis<dis[v]){
                dis[v]=dis[u]+edge[i].dis;
                if (!vis[v]){
                    vis[v]=1;q.push(v);tot[v]++;
                    if (tot[v]>n)return true;
                }
            }
        }
    }
    return false;
}
int main(){file();
    T=read();
    while(T--){
        n=read();m=read();
        for (int i=1;i<=n;i++){
            head[i]=0;dis[i]=1<<30;tot[i]=0;vis[i]=0;
        }
        for (int i=1;i<=m;i++){
            x=read();y=read();t=read();
            add(x,y,t);if (t>=0)add(y,x,t);
        }
        if (spfa())printf("YE5\n");
        else printf("N0\n");
    }
}
