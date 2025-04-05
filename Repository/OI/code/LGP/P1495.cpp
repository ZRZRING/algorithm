#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#define int long long
using namespace std;
const int orz=500100;
int n,a[orz],p[orz],M=1,ans;
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
int exgcd(int a,int b,int &x,int &y){
    if (!b){x=1;y=0;return a;}
    int d=exgcd(b,a%b,y,x);y-=a/b*x;
    return d;
}
int inv(int a,int b){//求a在%b意义下的逆元
    int x,y;exgcd(a,b,x,y);
    return (x%b+b)%b;//exgcd求出来是负数，需要处理一下
}
int mul(int x,int y){
    int res=0;
    x=(x%M+M)%M;y=(y%M+M)%M;
    while (y){
        if (y&1)res=(res+x)%M;
        x=(x<<1)%M;y>>=1;
    }
    return res;
}
signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        p[i]=read();a[i]=read();M*=p[i];
    }
    for (int i=1;i<=n;i++){
        int m=M/p[i],inv_m=inv(m,p[i]);
        ans=(ans+mul(mul(a[i],m),inv_m))%M;
    }
    printf("%lld\n",ans);
    return 0;
}
