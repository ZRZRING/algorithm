#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct hh{
    int eat,get;
}a[1000100];
int n,sum[1000100],dp[201][40001];
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
int cmp(hh a,hh b){
    return a.eat>b.eat;
}
int main(){file();
    n=read();memset(dp,127,sizeof(dp));
    for (int i=1;i<=n;i++){
        a[i].get=read();a[i].eat=read();
    }
    sort(a+1,a+n+1,cmp);dp[0][0]=0;
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i].get;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<=sum[i];j++){
            if (j>=a[i].get)dp[i][j]=min(dp[i][j],max(dp[i-1][j-a[i].get],j+a[i].eat));
            dp[i][j]=min(dp[i][j],max(dp[i-1][j],sum[i]-j+a[i].eat));
        }
    }int ans=2147483647;
    for (int i=0;i<=sum[n];i++){
        ans=min(ans,dp[n][i]);
    }
    printf("%d",ans);
}