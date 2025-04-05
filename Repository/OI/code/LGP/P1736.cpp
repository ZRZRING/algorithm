#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <bitset>
using namespace std;
const int orz=2505;
int n,m,cnt,ans,dp[orz][orz],ver[orz][orz],hor[orz][orz],a[orz][orz];
inline int read(){
    int sym(0),res(0);char ch(0);
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
            a[i][j]=read();
            if (!a[i][j]){
                ver[i][j]=ver[i-1][j]+1;hor[i][j]=hor[i][j-1]+1;
            }else{
                dp[i][j]=min(dp[i-1][j-1],min(ver[i-1][j],hor[i][j-1]))+1;
                ans=max(ans,dp[i][j]);
            }
        }
    }
    memset(hor,0,sizeof(hor));memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++){
        for (int j=m;j>=1;j--){
            if (!a[i][j])hor[i][j]=hor[i][j+1]+1;
            else dp[i][j]=min(dp[i-1][j+1],min(ver[i-1][j],hor[i][j+1]))+1;
            ans=max(ans,dp[i][j]);
        }
    }
    printf("%d",ans);
    return 0;
}