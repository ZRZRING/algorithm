#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct{
    int ver,pre,nxt;
}edge[1000100];
int cnt,head[1000100],n,q,dis[1000100],f[1001][1001];
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
void dp(int u){
    f[u][0]=0;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;dp(v);
        for (int j=q;j>=0;j--){
            for (int k=j;k>=0;k--){
                f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]);
            }
        }
    }
    if (u!=0){
        for (int i=q;i>=1;i--){
            f[u][i]=f[u][i-1]+dis[u];
        }
    }
}
int main(){file();
    n=read(),q=read();
    for (int i=1;i<=n;i++){
        int x=read();dis[i]=read();
        add(x,i);
    }
    memset(f,207,sizeof(f));dp(0);
    printf("%d",f[0][q]);
    return 0;
}