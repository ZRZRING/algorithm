#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <bitset>
#define int long long
using namespace std;
int n,k,ans;
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
signed main(){
    n=read();k=read();ans=n*k;
    for (int l=1,r,len,i;l<=n;l=r+1){
        i=k/l;if (!i)r=n;else r=min(n,k/i);
        len=r-l+1;ans-=len*i*(l+r)/2;
    }
    printf("%lld",ans);
    return 0;
}