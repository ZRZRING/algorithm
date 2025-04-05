#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N],b[N];
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
    int T=read();
    while (T--){
        n=read();int ans=0,ji=0,ou=0;
        for (int i=1;i<=n;i++){
            a[i]=read();
            if (a[i]%2==0)ou++;else ji++;
        }
        m=read();
        for (int i=1;i<=m;i++){
            int x=read();
            if (x%2==0)ans+=ou;else ans+=ji;
        }printf("%lld\n",ans);
    }
    return 0;
}