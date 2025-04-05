#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[2000100];
ll f[2000100][2],ans,tmp;
int n,m,cnt,x1,x2,cut,head[2000100],dis[2000100];
bool vis[2000100];
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
void add(int u,int v){
    edge[cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
void dfs(int u,int last){
    vis[u]=1;
    for (int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (v==last)continue;
        if (vis[v]){
            x1=u;x2=v;cut=i;continue;
        }
        dfs(v,u);
    }
}
void dp(int u,int last){
    f[u][0]=0;f[u][1]=dis[u];
    for (int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (i==cut||(i^1)==cut||v==last)continue;
        dp(v,u);
        f[u][0]+=max(f[v][1],f[v][0]);
        f[u][1]+=f[v][0];
    }
}
signed main(){file();
    n=read();memset(head,255,sizeof(head));
    for (int u=1;u<=n;u++){
        dis[u]=read();int v=read();
        add(u,v);add(v,u);
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            dfs(i,0);
            dp(x1,0);tmp=f[x1][0];
            dp(x2,0);
            if (f[x2][0]>tmp)tmp=f[x2][0];
            ans+=tmp;
        }
    }
    cout<<ans;
    return 0;
}