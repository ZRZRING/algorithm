#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int cnt,head[100010],u,r[100010],t[100010],vis[100010],dis[100010],flag,tot[100010],j,n,T;
struct EDGE{
    int nxt,ver,dis;
}edge[100010];
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
int SPFA(){
    queue<int>q;
    memset(dis,0xcf,sizeof(dis));
    memset(tot,0,sizeof(tot));
    memset(vis,0,sizeof(vis));
    q.push(24);dis[24]=0;vis[24]=1;tot[24]++;
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            if (dis[v]<dis[u]+edge[i].dis) {
                dis[v]=dis[u]+edge[i].dis;
                if (!vis[v]){
                    tot[v]++;vis[v]=1;q.push(v);
                    if (tot[v]>=24)return 0;
                }
            }vis[u]=0;
        }
    }
    return 1;
}
int main(){file();
    T=read();
    while (T--){
        memset(t,0,sizeof(t));flag=0;
        for (int i=0;i<=23;i++)r[i]=read();
        n=read();
        for (int i=1;i<=n;i++)t[read()]++;
        for (j=0;j<=n;j++){
            memset(tot,0,sizeof(tot));
            memset(head,0,sizeof(head));
            cnt=0;
            for (int i=0;i<=23;i++){
                if(i>0)add(i-1,i,0);
                if(i>0)add(i,i-1,-t[i]);
                if (i>=8)add(i-8,i,r[i]);
                if (i<8)add(i+16,i,r[i]-j);
            }
            add(24,0,0);add(0,24,-t[0]);add(24,23,j);
            if (SPFA()){
                flag=1;break;
            }
        }
        if (flag==0)printf("No Solution\n");
        else printf("%d\n",j);
    }
    return 0;
}