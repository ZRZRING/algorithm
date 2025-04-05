#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010,p=1e9+7;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m;
int main(){
    int type=read();n=read();m=read();
    long long ans=1;int p=read();
    for (int i=n-(m<<1)+2;i<=n-m+1;i++){
        ans=ans*i%p;
    }
    printf("%lld\n",ans);
    return 0;
}