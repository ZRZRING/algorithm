#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll n,m,dp[10][5000][100],p[1000100],ans;
inline ll read(){
    ll sym=0,res=0;char ch=0;
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
    for (ll i=0;i<(1<<n);i++){
        p[i]=!(i&(i<<1));
    }
    dp[0][0][0]=1;
    for (ll i=1;i<=n;i++){
        for (ll j=0;j<(1<<n);j++){
            if (!p[j])continue;
            ll tj=j,add=0;
            while (tj){
                add+=(tj&1);tj>>=1;
            }
            for (ll last=0;last<(1<<n);last++){
                if (!p[last])continue;
                if (last&(j<<1) || last&j || last&(j>>1))continue;
                for (ll k=add;k<=m;k++){
                    dp[i][j][k]+=dp[i-1][last][k-add];
                }
            }
        }
    }
    for (ll i=0;i<(1<<n);i++){
        ans+=dp[n][i][m];
    }
    printf("%lld",ans);
}