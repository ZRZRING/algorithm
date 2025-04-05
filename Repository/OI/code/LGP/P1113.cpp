#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <bitset>
using namespace std;
const int orz=500100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt,ans,dis[orz],vis[orz],a[orz],d[orz];
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
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x=read();a[x]=read();int y=read();
        while (y){
            add(y,x);y=read();d[x]++;
        }
    }
    queue<int>q;
    q.push(1);vis[1]=1;dis[1]=a[1];
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;dis[v]=max(dis[u]+a[v],dis[v]);
            if (!--d[v])q.push(v);
        }
    }
    /*for (int i=1;i<=n;i++){
        printf("%d\n",dis[i]);
    }*/
    for (int i=1;i<=n;i++){
        ans=max(ans,dis[i]);
    }
    printf("%d\n",ans);
    return 0;
}