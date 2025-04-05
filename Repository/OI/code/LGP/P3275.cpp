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
}edge[1000100];
int head[1000100],n,m,cnt,vis[1000100],dis[1000100],tot[1000100],ans;
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
//    edge[cnt].pre=u;
    head[u]=cnt;
}
int SPFA(){
    queue<int>q;q.push(0);vis[0]=1;tot[0]=1;
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            if (dis[u]+edge[i].dis>dis[v]){
                dis[v]=dis[u]+edge[i].dis;
                if (!vis[v]){
                    q.push(v);vis[v]=1;tot[v]=tot[u]+1;
                    if (tot[v]>n+1)return 1;
                }
            }
        }
        vis[u]=0;
    }
    return 0;
}
signed main(){file();
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int tmp=read(),u=read(),v=read();
        if(tmp==1)add(u,v,0),add(v,u,0);
        if(tmp==2){
            if (u==v){
                printf("-1");return 0;
            }
            add(u,v,1);
        }
        if(tmp==3)add(v,u,0);
        if(tmp==4){
            if (u==v){
                printf("-1");return 0;
            }
            add(v,u,1);
        }
        if(tmp==5)add(u,v,0);
    }
    for (int i=n;i>=1;i--){
        add(0,i,1);
    }
    /*for (int i=1;i<=cnt;i++){
        printf("%d %d %d\n",edge[i].pre,edge[i].ver,edge[i].dis);
    }*/
    if (SPFA()){
        //for (int i=1;i<=n;i++)printf("%d\n",dis[i]);
        printf("-1");return 0;
    }
    for (int i=1;i<=n;i++){
        //printf("%d\n",dis[i]);
        ans+=dis[i];
    }printf("%lld",ans);
    return 0;
}