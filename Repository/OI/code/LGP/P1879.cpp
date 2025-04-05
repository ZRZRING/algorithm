#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=100000000;
int n,m,a[1000100],dp[5002][5002],p[1000100],ans;
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
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int x=read();a[i]=(a[i]<<1)+x;
        }
    }
    for (int i=0;i<(1<<m);i++){
        p[i]=!(i&(i<<1));
    }dp[0][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<(1<<m);j++){
            if (p[j]&&(j&a[i])==j){
                for (int k=0;k<(1<<m);k++){
                    if ((k&j)==0){
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                    }
                }
            }
        }
    }
    for (int i=0;i<(1<<m);i++){
        cout<<dp[n][i]<<endl;ans=(ans+dp[n][i])%mod;
    }
    printf("%d",ans);
}