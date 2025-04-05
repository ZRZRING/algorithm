#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[1000100];
int head[1000100],n,m,cnt;
int dis[1001][1001],sum[1001][1001],w[1000100],dp[1000100],ans,p;
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
int main(){file();
    n=read();m=read();p=read();
    memset(dp,0xcf,sizeof(dp));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dis[i][j]=read();
        }
    }
    for (int i=1;i<=n;i++){
        w[i]=read();
    }dp[0]=0;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            int pre=j-1;if (!pre)pre=n;
            int sum=dis[pre][i];
            for (int k=1;k<=p;k++){
                if (i-k<0) break;
                dp[i]=max(dp[i],dp[i-k]+sum-w[pre]);
                pre--;if (!pre)pre=n;
                sum+=dis[pre][i-k];
            }
        }
    }
    printf("%d",dp[m]);
    return 0;
}