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
int num[10010][100],dp[10010][100],ans;
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
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int a=read(),b=read(),c=read(),t,love=0,fear=0;
        for (int j=1;j<=b;j++)t=read(),t=(t-a+n)%n,love|=(1<<t);
        for (int j=1;j<=c;j++)t=read(),t=(t-a+n)%n,fear|=(1<<t);
        for (int j=0;j<32;j++){
            if ((~j&love)||(j&fear))num[a][j]++;
        }
    }
    for (int k=0;k<32;k++){
        memset(dp[0],128,sizeof(dp[0]));dp[0][k]=0;
        for (int i=1;i<=n;i++){
            for (int j=0;j<32;j++){
                dp[i][j]=max(dp[i-1][(j&15)<<1],dp[i-1][(j&15)<<1|1])+num[i][j];
            }
        }
        if (ans<dp[n][k])ans=dp[n][k];
    }
    printf("%d",ans);
    return 0;
}