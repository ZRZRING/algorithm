#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N];
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
    n=read();int x=0,y=0;
    for (int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n>>1;i++){
        x+=a[i];
    }
    for (int i=(n>>1)+1;i<=n;i++){
        y+=a[i];
    }printf("%lld",x*x+y*y);
    return 0;
}