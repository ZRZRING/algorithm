#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,nxt,dis;
}edge[1000100];
int head[1000100],d1[1000100],d2[1000100],ans,now,f[1000100],n,cnt;
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
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa)continue;
        dp(v,u);
        if (d1[v]+1>d1[u]){
            d2[u]=d1[u];d1[u]=d1[v]+1;
        }else if (d1[v]+1>d2[u]){
            d2[u]=d1[v]+1;
        }
    }
    ans=max(ans,d1[u]+d2[u]);
}
void dfs(int u,int fa){
    int num=0;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa)continue;
        if (d1[u]==d1[v]+1)num++;
    }
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa)continue;
        if (d1[u]!=d1[v]+1||d1[u]==d1[v]+1&&now>1){//如果它不是最大子树或它是唯一的最大子树
            f[v]=max(f[u],d1[u])+1;
        }else{
            f[v]=max(f[u],d2[u])+1;
        }
        dfs(v,u);
    }
}
int main(){file();
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    dp(0,-1);dfs(0,-1);
    for (int i=0;i<n;i++){
        if (d1[i]+max(f[i],d2[i])==ans){
            printf("%d\n",i);
        }
    }
    return 0;
}