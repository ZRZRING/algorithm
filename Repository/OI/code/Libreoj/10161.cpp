#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[1000100];
int head[1000100],n,m,cnt,f[100010][3];
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
void dp(int u,int fa){
    if (u<=m)return;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa)continue;dp(v,u);
        f[u][0]+=min(f[v][0]-1,min(f[v][1],f[v][2]));
        f[u][1]+=min(f[v][0],min(f[v][1]-1,f[v][2]));
        f[u][2]+=min(f[v][0],min(f[v][1],f[v][2]));
    }
    f[u][0]++;f[u][1]++;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int color=read();
        f[i][color]=1;f[i][color^1]=f[i][2]=1<<30;
    }
    for (int i=1;i<=n-1;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    dp(m+1,0);
    printf("%d",min(f[m+1][0],min(f[m+1][1],f[m+1][2])));
    return 0;
}