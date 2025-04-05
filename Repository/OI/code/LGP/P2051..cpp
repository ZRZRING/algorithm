#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const ll mod=9999973;
ll n,m,dp[101][101][101],ans;
inline ll read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
ll C(int x){
    return ((x-1)*x/2)%mod;
}
int main(){file();
    n=read();m=read();dp[0][0][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=m;j++){
            for (int k=0;k<=m-j;k++){//dp[i][j][k]表示i行放j列1和k列2
                dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%mod;//不放
                if (k>=1){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j+1][k-1]*(j+1))%mod;//放一个1
                }
                if (j>=1){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k]*(m-j-k+1))%mod;//放一个0
                }
                if (j>=2){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-2][k]*C(m-j-k+2))%mod;//放两个0
                }
                if (k>=2){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j+2][k-2]*C(j+2))%mod;//放两个1
                }
                if (k>=1){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k-1]*j*(m-j-k+1))%mod;//放一个1一个0
                }
            }
        }
    }
    for (int i=0;i<=m;i++){
        for (int j=0;j<=m-i;j++){
            ans=(ans+dp[n][i][j])%mod;
        }
    }
    printf("%d",ans);
}