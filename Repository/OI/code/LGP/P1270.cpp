#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int orz=500100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt,size[orz],v=2;
int dis[orz],s,l,r,f[5001][1001],ans;
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
    edge[cnt].pre=u;
    edge[cnt].dis=t;
    head[u]=cnt;
}
void dfs(int u){
    int t=read()<<1,tmp=read();v++;add(u,v,t);
    if (tmp){
        add(v,v+1,tmp*5);dis[++v]=tmp;
    }else{
        dfs(v);
    }
    t=read()<<1;tmp=read();v++;add(u,v,t);
    if (tmp){
        add(v,v+1,tmp*5);dis[++v]=tmp;
    }else{
        dfs(v);
    }
}
void dp(int u){
    f[u][0]=dis[u];
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;dp(v);
        for (int j=s;j>=edge[i].dis;j--){
            for (int k=j-edge[i].dis;k>=0;k--){
                f[u][j]=max(f[u][j],f[v][k]+f[u][j-k-edge[i].dis]);
            }
        }
    }
}
int main(){//file();
    s=read()-1;
    int t=read()<<1;dis[2]=read();add(1,2,t);
    if (!dis[2])dfs(2);dp(1);
    for (int i=1;i<=s;i++){
        ans=max(ans,f[1][i]);
    }
    printf("%d",f[1][s]);
    return 0;
}