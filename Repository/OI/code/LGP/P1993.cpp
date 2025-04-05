#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre;
}edge[1000100];
queue<int>q;
int tot[1000100],cnt,head[1000100],dis[1000100],vis[1000100],n,m,tmp,x,y,t;
int read(){
    int res=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return res;
}
void add(int u,int v,int t){
    edge[++cnt].ver=v;
    edge[cnt].dis=t;
    edge[cnt].pre=u;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
bool SPFA(int u){
    vis[u]=1;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (dis[u]+edge[i].dis<dis[v]){
            dis[v]=dis[u]+edge[i].dis;
            if (vis[v])return 0;
            if (!SPFA(v))return 0;
        }
    }
    vis[u]=0;
    return 1;
}
int main(){file();
    memset(dis,127,sizeof(dis));dis[0]=0;
    n=read();m=read();
    for (int i=1;i<=n;i++){
        add(0,i,0);
    }
    for (int i=1;i<=m;i++){
        tmp=read();x=read();y=read();
        if (tmp==1){
            t=read();add(x,y,-t);
            //y-x<=-t
        }
        if (tmp==2){
            t=read();add(y,x,t);
            //x-y<=t
        }
        if (tmp==3){
            add(x,y,0);add(y,x,0);
        }
    }
    /*for (int i=1;i<=cnt;i++){
        cout<<edge[i].pre<<' '<<edge[i].ver<<' '<<edge[i].dis<<endl;
    }*/
    if (SPFA(0))printf("Yes");
    else printf("No");
}