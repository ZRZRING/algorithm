#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,nxt,pre,dis;
}edge[1000100];
int cnt,n,m,val[1000100],head[1000100],dp[5001][5001];
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
int dfs(int u){
    if (u>=n-m+1){
        dp[u][1]=val[u];return 1;
    }
    int sum=0;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver,tmp=dfs(v);sum+=tmp;
        for (int j=sum;j>=1;j--){
            for (int k=1;k<=tmp;k++){
                if (j<k)continue;
                dp[u][j]=max(dp[u][j],dp[v][k]+dp[u][j-k]-edge[i].dis);
            }
        }
    }
    return sum;
}
int main(){
    n=read();m=read();
    memset(dp,~0x3f,sizeof(dp));
    for (int u=1;u<=n-m;u++){
        int tmp=read();
        for (int j=1;j<=tmp;j++){
            int v=read(),t=read();
            add(u,v,t);
        }
    }
    for (int i=n-m+1;i<=n;i++){
        val[i]=read();
    }
    for (int i=1;i<=n;i++){
        dp[i][0]=0;
    }
    dfs(1);
    for (int i=n;i>=1;i--){
        if (dp[1][i]>=0){
            printf("%d",i);break;
        }
    }
}