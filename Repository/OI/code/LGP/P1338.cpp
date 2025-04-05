#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=200010;
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
    n=read();m=read();int l=1,r=n;
    for (int i=1;i<=n;i++){
        if ((n-i)*(n-i-1)/2>=m)a[l++]=i;
        else a[r--]=i,m-=r-l+1;
    }
    for (int i=1;i<=n;i++){
        printf("%lld ",a[i]);
    }
    return 0;
}