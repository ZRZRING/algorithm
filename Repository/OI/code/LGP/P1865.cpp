#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
const int orz=1000100;
/*struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];*/
int head[orz],n,m,cnt,prime[orz],vis[orz*2],sum[orz];
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
/*void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}*/
void make(){
    vis[1]=1;
    for (int i=2;i<=m;i++){
        if (!vis[i])prime[++cnt]=i;
        for (int j=1;j<=cnt&&prime[j]*i<=m;j++){
            vis[i*prime[j]]=1;
            if (i%prime[j]==0)break;
        }
    }
    for (int i=2;i<=m;i++){
        sum[i]=sum[i-1]+(!vis[i]);
    }
}
int main(){file();
    n=read();m=read();make();
    for (int i=1;i<=n;i++){
        int l=read(),r=read();
        if (r>m||l<1){
            printf("Crossing the line\n");continue;
        }
        printf("%d\n",sum[r]-sum[l-1]);
    }
    return 0;
}