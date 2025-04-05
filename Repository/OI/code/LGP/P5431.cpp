#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define rint register int
using namespace std;
void file() {
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=5000010;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m,c,a[N],mul[N]={1},k[N]={1},ans,p;
int power(int a,int x){
    int res=1;
    while (x){
        if (x&1)res=(1ll*res*a)%p;
        x>>=1;a=(1ll*a*a)%p;
    }
    return res;
}
int main(){
    n=read();p=read();c=read();
    for (rint i=1;i<=n;i++){
        k[i]=1ll*k[i-1]*c%p;
    }
    for (rint i=1;i<=n;i++){
        a[i]=read();
        mul[i]=1ll*mul[i-1]*a[i]%p;
    }
    int inv=power(mul[n],p-2);
    for (rint i=n;i>=1;i--){
        ans=(ans+1ll*inv*mul[i-1]%p*k[i]%p)%p;
        inv=1ll*inv*a[i]%p;
    }
    printf("%lld",ans);
    return 0;
}