#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,nxt,dis;
}edge[1000100];
int head[1000100],cnt,f[100010][3],dis[1000100],n,p[1000100];
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
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
int dp(int u){
    int d=1<<30;f[u][2]=dis[u];
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;dp(v);
        f[u][0]+=min(f[v][2],f[v][1]);
        f[u][1]+=min(f[v][2],f[v][1]);
        d=min(d,f[v][2]-min(f[v][2],f[v][1]));
        f[u][2]+=min(f[v][0],min(f[v][1],f[v][2]));
    }
    f[u][1]+=d;
}
int main(){file();
    n=read();
    for (int i=1;i<=n;i++){
        int u=read(),size;dis[u]=read();size=read();
        for (int j=1;j<=size;j++){
            int v=read();add(u,v);p[v]=1;
        }
    }int root=1;while(p[root])root++;dp(root);
    printf("%d",min(f[root][1],f[root][2]));
    return 0;
}