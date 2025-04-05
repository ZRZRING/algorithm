#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=1000010;
int n,m,sum[N],a[N],s[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read();sum[i]=sum[i-1]+a[i];
    }
    int ave=sum[n]/n,ans=0;
    for (int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i]-ave;
    }
    sort(s+1,s+n+1);int mid=s[(n>>1)+1];
    for (int i=1;i<=n;i++){
        ans+=abs(mid-s[i]);
    }printf("%lld\n",ans);
    return 0;
}
