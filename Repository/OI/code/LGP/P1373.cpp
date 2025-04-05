#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int n,m,k,a[1001][1001],dp[805][805][22][2],ans;
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
    n=read();m=read();k=read();k++;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=read();
            dp[i][j][a[i][j]][0]=1;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int c=0;c<=k;c++){
                dp[i][j][c][0]=(dp[i][j][c][0]+dp[i-1][j][(c+k-a[i][j])%k][1])%mod;
                dp[i][j][c][0]=(dp[i][j][c][0]+dp[i][j-1][(c+k-a[i][j])%k][1])%mod;
                dp[i][j][c][1]=(dp[i][j][c][1]+dp[i-1][j][(c+a[i][j])%k][0])%mod;
                dp[i][j][c][1]=(dp[i][j][c][1]+dp[i][j-1][(c+a[i][j])%k][0])%mod;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ans=(ans+dp[i][j][0][1])%mod;
        }
    }
    printf("%d",ans);
}