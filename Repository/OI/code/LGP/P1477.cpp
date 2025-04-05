#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
struct EDGE{
    int ver,nxt;
}edge[N];
int n,m,dis[N],head[N],vis[N],pre[N],cnt,d[N],res[N];
queue<int>q;
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void topo(){
    for (int i=1;i<=n;i++){
        if (!d[i])q.push(i);
    }
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;d[v]--;
            if (!d[v]){
                if (vis[v]){
                    cnt++;while (pre[v])v=pre[v],res[cnt]++;
                }else vis[v]=1,q.push(v),dis[v]=dis[u]+1;
            }
        }
    }
}
int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int u=read(),v=read();add(u,v);d[v]++;
    }
    cnt=0;topo();
    if (cnt){
        int ans=res[1];
        for (int i=2;i<=n;i++){
            ans=gcd(ans,res[i]);
        }
        for (int i=3;i<=ans;i++){
            if (ans%i==0){
                printf("%d",i);break;
            }
        }
        printf("%d",ans);
    }else{
        printf("3\n");
        int ans=0;
        for (int i=1;i<=n;i++){
            ans=max(ans,dis[i]);
        }printf("%d",ans);
    }
    return 0;
}